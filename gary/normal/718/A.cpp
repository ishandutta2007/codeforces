#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,t,pos=-1,fir=-1;
string num;
int main(){
	scanf("%d %d",&n,&t);
	cin>>num;
	rb(i,0,n-1){
		if(num[i]=='.'){
			pos=i;break;
		}
	}
	if(pos<0){cout<<num;return 0;}
	
	rb(i,pos+1,n-1){
		if(num[i]>='5'){
			fir=i;
			break;
		}
	}
	if(fir==-1){cout<<num;return 0;}
	rl(i,fir,pos+1){
//		cout<<i<<endl;
		if(num[i]>'9'){
			if(i!=pos+1){
				num[i-1]++;
				num[i]-=10;
			}
			else{
				num[i-2]++;
				num[i]-=10;
			}
		}
		if(num[i]>='5'&&t){
			t--;
			num[i]='#';
			fir=i;
			if(i!=pos+1){
				num[i-1]++;
			}
			else{
				num[i-2]++;
			}
		}
	}
	rl(i,pos-1,1){
		if(num[i]>'9'){
			num[i]-=10;
			num[i-1]++;
		}
	}
	if(num[0]>'9'){
		num[0]-=10;
		cout<<1;
	}
	int TO=fir;
	for(int i=fir-1;i>pos;i--){
		if(num[i]!='0') break;
		TO=i;
	}
	if(TO==pos+1){
		rb(i,0,pos-1){
			cout<<num[i];
		}
	}
	else{
		rb(i,0,TO-1){
			cout<<num[i];
		}
	}
	return 0;
};