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
LL n,m;
const LL MOD=1e9+7;
int main(){
	scanf("%I64d %I64d",&n,&m);
//	if(m>n) m=n;
	LL res=(n%MOD)*(m%MOD);
//	cout<<res<<endl;
	if(res<0){
			res+=((-res)/MOD+1)*MOD;
			res%=MOD;
		}
	res%=MOD;
	for(LL i=1;i*i<=n;i++){
		if(i<=m){
//			if((i+1000)*(i+1000)>n||i<=1000)cout<<"*"<<i<<endl;
		res=res-((i%MOD)*((n/i)%MOD))%MOD+MOD;
		res%=MOD;
		}
		LL truei_d=(n/(i+1))+1,truei_u=n/i;
		truei_u=min(truei_u,m);
		LL tot=truei_u-truei_d;
		tot++;
		if(truei_d<=i){
			truei_d=i+1;
		} 
		if(truei_u>=truei_d){
//		if((i+1000)*(i+1000)>n||i<=1000)cout<<i<<"*"<<truei_d<<","<<truei_u<<endl;
		LL tmp_res=0;
		LL val,r=truei_u,l=truei_d;
		if ((r + l) % 2 == 0){
			val = (r + l)/2 % MOD;
			val = val * ((r - l + 1) % MOD) % MOD; 
			val = val * i % MOD;
		}
		else{
			val = (r - l + 1)/2 % MOD;
			val = val * ((r + l) % MOD) % MOD;
			val = val * i % MOD;
		}
		tmp_res=val;
		tmp_res%=MOD;
		res=res-tmp_res+MOD;
		res%=MOD;
		}
	}
	printf("%I64d\n",res);
	return 0;
}