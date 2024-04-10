#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int q;
ll last,mx[400005][20],a[400005],sum[400005][20],up[400005][20];
int cnt = 1,dep[400005],go[400005][20],num[400005];
int main(){
	scanf("%d",&q);
	memset(go,-1,sizeof(go));
	memset(mx,-1LL,sizeof(mx));
	memset(up,-1LL,sizeof(up));
	rep(i,20) mx[1][i] = 0;
	num[1] = 1;
	rep(t,q){
		int ty; scanf("%d",&ty);
		if(ty == 1){
			ll p; ll q; scanf("%lld%lld",&p,&q);
			p ^= last;
			q ^= last;
			dep[cnt+1] = dep[p]+1;
			a[cnt+1] = q;
			rep(j,20){
				if(j==0){
					go[cnt+1][0] = p;
				}
				else{
					if(go[cnt+1][j-1] == -1){
						go[cnt+1][j] = -1;
					}
					else{
						go[cnt+1][j] = go[go[cnt+1][j-1]][j-1];
					}
				}
			}
			rep(j,20){
				if(j==0){
					mx[cnt+1][0] = q;
				}
				else{
					if(go[cnt+1][j-1] == -1){
						mx[cnt+1][j] = mx[cnt+1][j-1];
					}
					else{
						mx[cnt+1][j] = max(mx[cnt+1][j-1],mx[go[cnt+1][j-1]][j-1]);
					}
				}
			}
			int cur = go[cnt+1][0];
			int to = -1;
			for(int j=19;j>=0;j--){
				if(cur >= 1 && mx[cur][j] >= q){
					if(j==0) to = cur;
					else{
						if(mx[cur][j-1] >= q);
						else cur = go[cur][j-1];
					}
				}
				else{
					break;
				}
			}
			if(to >= 1){
				up[cnt+1][0] = to;
				sum[cnt+1][0] = q;
				num[cnt+1] = num[to]+1;
				for(int j=1;j<20;j++){
					if(up[cnt+1][j-1] == -1){
						up[cnt+1][j] = -1;
						sum[cnt+1][j] = sum[cnt+1][j-1];
					}
					else{
						up[cnt+1][j] = up[up[cnt+1][j-1]][j-1];
						sum[cnt+1][j] = sum[cnt+1][j-1]+sum[up[cnt+1][j-1]][j-1];
					}
				}
			}
			else{
				rep(j,20) sum[cnt+1][j] = q;
				num[cnt+1] = 1;
			}
			cnt++;
		}
		else{
			ll p; ll q; scanf("%lld%lld",&p,&q);
			p ^= last;
			q ^= last;
			if(sum[p][19] <= q){
				printf("%d\n",num[p]);
				last = num[p];
				continue;
			}
			int ans = 0;
			for(int i=19;i>=0;i--){
				if(sum[p][i] > q){
					if(i == 0){
						printf("%d\n",ans);
						last = ans;
					}
					else{
						if(sum[p][i-1] <= q){
							ans += (1<<(i-1));
							q -= sum[p][i-1];
							p = up[p][i-1];
						}
					}
				}
				else assert(0);
			}
		}
	}
}