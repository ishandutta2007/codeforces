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
map<int,int> M;
int main(){
	int n;
	int a[100000+10];
	scanf("%d",&n);
	bool flag=0;
	LL sum=0;
	rb(i,1,n){
		scanf("%d",&a[i]);
		M[a[i]]++;
		flag=(flag|bool(a[i]));
		sum+=a[i];
	}
	map<int,int> :: IT ite;
	int have=0;
	for(ite=M.begin();ite!=M.end();ite++){
		if(ite->FIR==0&&ite->SEC>=2){
			flag=false;
			break;
		}
		if(ite->SEC>2){
			flag=false;
			break;
		}
		if(have){
			if(ite->SEC==2){
				flag=0;
				break;
			}
		}
		else{
			have=(ite->SEC==2);
		}
		if(ite->SEC==2&&M[(ite->FIR)-1]){
			flag=0;
			break;
		}
	}
	if(!flag){
		cout<<"cslnb"<<endl;
		return 0;
	}
	sum=0;
	sort(a+1,a+1+n);
	int las=0;
	rb(i,1,n){
		sum+=a[i]-las;
		las=i;
	}
//	cout<<sum<<endl;
	cout<<(((sum)&1)? "sjfnb":"cslnb")<<endl; 
	return 0;
}