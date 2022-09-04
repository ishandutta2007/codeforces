#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int q;
	scanf("%d",&q);
	LL value[64];
	MEM(value);
	LL MOD[64];
	for(int i=1;i<64;i++)
	MOD[i]=(1ll<<(i-1));
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1||t==2){
			LL x,k;
			scanf("%lld %lld",&x,&k);
			LL kk=x;
			int num=0;
			while(kk){
				num++;
				kk>>=1;
			}

			if(t==1){
				LL mod=MOD[num];
				value[num]=((value[num]-k)%mod+mod)%mod;
			}
			else if(t==2){
				for(int i=num;i<63;i++){
					LL mod=MOD[i];
					k%=mod;
					//printf("%lld\n",k);
					value[i]=((value[i]-k)%mod+mod)%mod;
					k*=2;
				}
			}
		}
		else{
			LL x;
			scanf("%lld",&x);
			LL k=x;
			int num=0;
			while(k){
				num++;
				k>>=1;
			}
			x-=value[num];
			if(x<MOD[num])
			x+=MOD[num];
		//	printf("%lld\n",x);
			while(x){
				LL mod=MOD[num];
				printf("%lld ",((x+value[num])%mod+mod)%mod+mod);
				num--;
				x>>=1;
			}
			printf("\n");
		}
	}
}