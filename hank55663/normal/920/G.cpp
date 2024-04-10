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
#define index Index
#define N 300005
using namespace std;
typedef long long LL;
vector<int> factor[1000005];
int f[1000005];
int prime[1000005];
int main(){
	for(int i=1;i<=1e6;i++)
	f[i]=-1;
	for(int i=2;i<=1e6;i++){
		for(int j=i;j<=1e6;j+=i){
			if(j!=i)
			prime[j]=1;
			factor[j].pb(i);
			if(!prime[i]){
				f[j]*=-1;
				if((j/i)%i==0){
					f[j]=0;
				}
			}
		}
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int x,p;
		LL k;
		scanf("%d %d %I64d",&x,&p,&k);
		if(p==1){
			printf("%d\n",x+k);
		}
		else{
			LL Min=1,Max=1e18;
			k+=x;
			int sum=0;
			for(auto it:factor[p]){
				k-=(x/it)*f[it]; 
			//	printf("%d %d\n",it,f[it]);
			}
		//	printf("%d\n",k);
			while(Min+1<Max){
				LL mid=(Min+Max)/2;
				LL sum=0;
				for(auto it:factor[p]){
					sum+=((mid)/it)*f[it];
				}
				if(mid-sum>=k){
					Max=mid;
				}
				else{
					Min=mid;
				}
			}
			printf("%lld\n",Max);
		}
	} 
}