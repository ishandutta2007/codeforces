#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
int n,m,a[(1<<22)];;
bool used[(1<<22)][2];
bool in[(1<<22)],ex[(1<<22)];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		ex[a[i]] = 1;
		if(a[i] == 0){
			puts("1");
			return 0;
		}
	}
	int ans = 0;
	for(int i=1;i<=m;i++){
		if(in[a[i]]) continue;
		queue<P>que;
		que.push(mp(a[i],0));
		in[a[i]] = 1;
		ans++;
		while(!que.empty()){
			P p = que.front(); que.pop();
			if(used[p.fi][p.sc]) continue;
			used[p.fi][p.sc] = 1;
			if(p.sc && ex[p.fi]) in[p.fi] = 1;
			for(int i=0;i<n;i++){
				if(!((p.fi>>i)&1)) continue;
				int go = p.fi-(1<<i);
				if(!used[go][p.sc]){
					que.push(mp(go,p.sc));
				}
			}
			if(!used[(1<<n)-1-p.fi][1] && ex[p.fi]){
				que.push(mp((1<<n)-1-p.fi,1));
			}
		}
	}
	cout<<ans<<endl;
}