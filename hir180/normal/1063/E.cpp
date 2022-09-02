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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,pp[1005],p[1005],cur[1005];
char f[1005][1005];
int ans[1005][1005];
P1 sol(){
	bool same = 0;
	bool en = 0;
	for(int i=1;i<=n;i++){
		if(p[i] == -1 && cur[i] == -1) same = 1;
		if(p[i] != cur[i]) en = 1;
	}
	if(!en) return mp(0,mp(0,0));
	if(!same){
		int val = -1, pos2 = -1;
		repn(i,n){
			if(cur[i] == -1) val = p[i], pos2 = i;
		}
		int pos = -1;
		repn(i,n){
			if(cur[i] == val) pos = i;
		}
		//swap(pos,pos2);
		swap(cur[pos],cur[pos2]);
		if(pos2 < pos){
			return mp(-1,mp(pos,pos2));
		}
		else{
			return mp(1,mp(pos,pos2));
		}
	}
	else{
		P pos[1005];
		rep(i,1005) pos[i] = mp(-1,-1);
		repn(i,n){
			if(p[i] != -1) pos[p[i]].fi = i;
		}
		repn(i,n){
			if(cur[i] != -1) pos[cur[i]].sc = i;
		}
		repn(i,n){
			if(pos[i].fi == -1) continue;
			if(pos[i].fi < pos[i].sc){
				int s = cur[1];
				cur[1] = cur[pos[i].fi];
				cur[pos[i].fi] = cur[pos[i].sc];
				cur[pos[i].sc] = s;
				return mp(INF,pos[i]);
			}
		}
		assert(0);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&pp[i]);
	for(int i=1;i<=n;i++) p[pp[i]] = i;
	for(int i=1;i<=n;i++){
		if(p[i] != i) goto bad;
	}
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) printf(".");
		puts("");
	}
	return 0;
	bad:;
	printf("%d\n",n-1);
	int loss = p[1];
	p[1] = -1;
	for(int i=1;i<=n;i++) cur[i] = i;
	for(int i=1;i<=n;i++){
		if(cur[i] == loss){
			if(1<=i-1 && i-1<=n){
				ans[n-1][i-2] = ans[n-1][i-1] = 1;
				cur[i] = i-1;
				cur[i-1] = -1;
			}
			else{
				ans[n-1][i-1] = ans[n-1][i] = -1;
				cur[i] = i+1;
				cur[i+1] = -1;
			}
		}
	}
	for(int i=n-2;i>=0;i--){
		P1 q = sol();
		if(q.fi != INF){
			ans[i][q.sc.fi-1] = ans[i][q.sc.sc-1] = q.fi;
		}
		else{
			ans[i][0] = ans[i][q.sc.fi-1] = ans[i][q.sc.sc-1] = -1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ans[i][j] == 0) printf(".");
			else if(ans[i][j] == 1) printf("/");
			else printf("\\");
		}
		puts("");
	}
}