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
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	LL n,m;
	scanf("%I64d %I64d",&n,&m);
	LL maxi,mini;
	if(m==0){
		printf("%I64d %I64d\n",n,n);
		return 0;
	}
	if(m==1){
		printf("%I64d %I64d\n",n-2,n-2);
	}
	else{
		if(m==2){
			printf("%I64d %I64d\n",max((LL)(0),n-2*m),n-3);
		}
		else{
			mini=max((LL)(0),n-2*m);
			rb(i,1,n){
				if(m<=0) break;
				m-=i-1;
				maxi=n-i;
			}
//			cout<<m<<endl;
			printf("%I64d %I64d\n",mini,maxi);
		}
	}
	return 0;
}