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
bool solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	int cnt[100005];
	fill(cnt,cnt+m+1,0);
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		cnt[x%m]++;
	}
	int ans=0;
	if(cnt[0])ans++;
	for(int i = 1;i<m;i++){
		if(i>m-i)break;
		if(i==m-i){
			if(cnt[i])ans++;
		}
		else{
			if(cnt[i]||cnt[m-i])
			ans+=max(abs(cnt[i]-cnt[m-i]),1);
		}
		
	}
	printf("%d\n",ans);
}
int main(){
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}