#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define index Index
using namespace std;
int cnt[20000005];
bool solve(){
	int c,d,x;
	scanf("%d %d %d",&c,&d,&x);
	LL ans=0;
	for(int i = 1;i*i<=x;i++){
		if(x%i==0){
			if((i+d)%c==0){
				ans+=cnt[(i+d)/c];
			//	printf("%d %d\n",(i+d)/c,x/i);
			//	if((i+d)/c!=1)ans++;
			}
			if(x/i!=i)
			if((x/i+d)%c==0){
				//if()
				ans+=cnt[(x/i+d)/c];
				//printf("%d %d\n",(x/i+d)/c,i);
			//	if((x/i+d)/c!=1)ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	cnt[1]=1;
	fill(cnt,cnt+20000005,1);
	for(int i = 2;i<=20000000;i++){
		if(cnt[i]==1){
			for(int j = i;j<=20000000;j+=i){
				cnt[j]*=2;
			}
		}
	}
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}