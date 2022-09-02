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
vector<int>edge[300005];
int n,m;
map<vector<int>,int>M;
int val[300005];
vector<int>chain[300005];
int num[300005],ans[300005];
int main(){
	scanf("%d%d",&n,&m);
	if(n<=1000 && m == n*(n-1)/2){
		puts("YES");
		rep(i,n) cout << 1 << " ";
		cout<<endl;
		return 0;
	}
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	repn(i,n) edge[i].pb(i);
	repn(i,n){
		SORT(edge[i]);
		ERASE(edge[i]);
	}
	int nxt = 1;
	repn(i,n){
		if(M.find(edge[i]) != M.end()) continue;
		M[edge[i]] = nxt++;
	}
	repn(i,n){
		val[i] = M[edge[i]];
	}
	repn(i,n){
		rep(j,edge[i].size()){
			int a = val[i];
			int b = val[edge[i][j]];
			if(a != b){
				chain[a].pb(b);
				chain[b].pb(a);
			}
		}
	}
	for(int i=1;i<300005;i++){
		SORT(chain[i]);
		ERASE(chain[i]);
	}
	vector<int>hoge;
	int beg = -1,pre = -1;
	for(int i=1;i<300005;i++){
		if(chain[i].size() == 1){
			beg = i;
			break;
		}
	}
	if(beg == -1){
		puts("NO");
		return 0;
	}
	while(1){
		hoge.pb(beg);
		if(chain[beg].size() >= 3){
			puts("NO");
			return 0;
		}
		for(int i=0;i<chain[beg].size();i++){
			if(chain[beg][i] == pre) continue;
			pre = beg;
			beg = chain[beg][i];
			goto nxt;
		}
		break; nxt:;
	}
	for(int i=0;i<hoge.size();i++) num[hoge[i]] = i+1;
	for(int i=1;i<=n;i++){
		ans[i] = num[val[i]];
		if(ans[i] == 0){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
}