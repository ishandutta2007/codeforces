#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
#define N 300005
using namespace std;
typedef long long LL;
LL f_pow(int a,int b,int mod){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1; 
	}	
	return res;
}
pii gcd(int a, int b){
    if(b == 0) return make_pair(1, 0);
    else{
        int p = a / b;
        pii q = gcd(b, a % b);
        return make_pair(q.second, q.first - q.second * p);
    }
}
int main(){
	LL a,b,p;
	LL x;
	while(scanf("%I64d %I64d %I64d %I64d",&a,&b,&p,&x)!=EOF){ 
	LL now=1;
	LL ans=0;
	for(int i=1;i<p;i++){
		now*=a;
		now%=p;
		LL need=b*f_pow(now,p-2,p)%p;
		LL res=need*(p-1)*f_pow(p-1,p-2,p);
		LL res2=i*p*((gcd(p,p-1).x%(p-1)+p-1)%(p-1)); 
	//	printf("%d %d %d %d\n",res%p,res%(p-1),res2%p,res2%(p-1));
		res+=res2;
		res%=p*(p-1);
		ans+=(x-res+p*(p-1))/(p*(p-1));
	//	printf("%d %d %d\n",ans,res,need);
	}
	printf("%I64d\n",ans);
	} 
}