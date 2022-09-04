#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
vector<pii> ans[5005];
int main(){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	int tot[5000];
	MEM(ans);
	int w[20];
	for(int i=0;i<n;i++)
		scanf("%d",&w[i]);
	reverse(w,w+n);
	for(int i=0;i<m;i++){
		char c[55];
		scanf("%s",c);
		int sum=0;
		for(int j=0;c[j]!=0;j++){
			sum<<=1;
			sum+=c[j]-'0';
		}
		tot[sum]++;
	}
	int cost[5005];
	for(int i=0;i<(1<<n);i++){
		int k=i;
		int now=0,sum=0;
		while(k){
			if(k&1)sum+=w[now];
			now++;
			k>>=1;
		}
		cost[i]=sum;
	}
	for(int i=0;i<(1<<n);i++){
		int x=((1<<n)-1)^i;
		ans[x].resize(1<<n);
		for(int j=0;j<(1<<n);j++){
			ans[x][i^j].x=cost[j];
			ans[x][i^j].y=tot[i^j];
		}
		sort(ans[x].begin(),ans[x].end());
		for(int j=1;j<ans[x].size();j++)
			ans[x][j].y+=ans[x][j-1].y;
	}
	while(q--){
		char c[20];
		int y;
		scanf("%s %d",c,&y);
		int sum=0;
		for(int j=0;c[j]!=0;j++){
			sum<<=1;
			sum+=c[j]-'0';
		}
		auto it=upper_bound(ans[sum].begin(),ans[sum].end(),mp(y+1,0));
		it--;
		printf("%d\n",it->y);
	}
}