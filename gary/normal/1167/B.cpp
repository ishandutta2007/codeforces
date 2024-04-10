//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<int,int> hav;
map<int,int> PU;
int res[7];
int main(){
	int have[6]={4, 8, 15, 16, 23, 42 };
	hav[4]=hav[8]=hav[15]=hav[16]=hav[23]=hav[42]=1;
	int a[7];
	cout<<"? 1 2"<<endl;fflush(stdout);
	int num;
	cin>>num;
	a[1]=num;
	cout<<"? 2 3"<<endl;fflush(stdout);
	cin>>num;
	a[2]=num;
	cout<<"? 3 4"<<endl;fflush(stdout);
	cin>>num;
	a[3]=num;
	cout<<"? 4 5"<<endl;fflush(stdout);
	cin>>num;
	a[4]=num;
	cout<<"! ";
	rb(i,1,4){
		int num1,num2;
		rb(j,1,6){
			if(a[i]%have[j]==0){
				if(hav[a[i]/have[j]]){
					num1=have[j];
					num2=a[i]/have[j];
				}
			}
		}
		if(i==1){
			res[1]=num1;
			res[2]=num2;
		}
		else{
			if(i==2){
				if(res[1]!=num1&&res[2]!=num1){
					res[3]=num1;
				}
				else{
					res[3]=num2;
				}
			}
			else{
				int now;
				now=(i==3)? 4:5;
				if(res[now-1]!=num1){
					res[now]=num1; 
				} 
				else{
				 	res[now]=num2;
				 } 
			}
		}
	}
	if(res[2]*res[3]!=a[2]) swap(res[1],res[2]);
	rb(i,1,5){
		cout<<res[i]<<" ";
		hav[res[i]]=0;
	}
	map<int,int> :: IT ite;
	for(ite=hav.begin();ite!=hav.end();ite++){
		if(ite->SEC){
			cout<<ite->FIR;
			break;
		}
	}
	return 0;
}