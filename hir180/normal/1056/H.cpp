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

int t;
int n,q;
vector<int>vi[300005];
bool used[300005];
int pre[300005];
vector<P>pos[300005];
int poss[300005];

int main(){
	cin >> t;
	while(t --){
		scanf("%d%d",&n,&q);
		rep(i,q) vi[i].clear();
		repn(i,n){
			pre[i] = -1;
			used[i] = 0;
			pos[i].clear();
		}
		rep(i,q){
			int k; scanf("%d",&k);
			rep(j,k){
				int a; scanf("%d",&a);
				vi[i].pb(a);
			}
		}
		bool answer = 0;
		// vs  (sum(k) / 614 * sum(k) )
		rep(i,q){
			//6/14 is the birthday of Kaede Takagaki !!
			if(vi[i].size() < 614) continue;
			rep(x,vi[i].size()) used[vi[i][x]] = 1;
			rep(x,vi[i].size()) poss[vi[i][x]] = x;
			rep(x,vi[i].size()) if(x) pre[vi[i][x]] = vi[i][x-1];
			rep(j,q){
				if(i == j) continue;
				bool in = 0;
				int prre = INF;
				rep(k,vi[j].size()){
					if(used[vi[j][k]]){
						if(in){
							int need = pre[vi[j][k]];
							int real = vi[j][k-1];
							if(need != real && prre < poss[vi[j][k]]){
								puts("Human"); answer = 1;
								goto end;
							}
						}
						in = 1;
						prre = min(prre,poss[vi[j][k]]);
					}
				}
			}
			rep(x,vi[i].size()) used[vi[i][x]] = 0;
			rep(x,vi[i].size()) if(x) pre[vi[i][x]] = -1;
		}
		end:;
		if(answer) continue;
		
		//
		rep(i,q){
			//6/14 is the birthday of Kaede Takagaki !!
			if(vi[i].size() >= 614) continue;
			rep(x,vi[i].size()){
				pos[vi[i][x]].pb(mp(i,x));
			}
		}
		//begpre[x]2
		repn(beg,n){
			rep(i,pos[beg].size()){
				int id = pos[beg][i].fi;
				int nm = pos[beg][i].sc;
				for(int j=nm+1;j<vi[id].size();j++){
					int cur = vi[id][j];
					int prre = vi[id][j-1];
					if(pre[cur] == -1){
						pre[cur] = prre;
					}
					else if(pre[cur] != prre){
						puts("Human"); answer = 1;
						goto end2;
					}
				}
			}
			rep(i,pos[beg].size()){
				int id = pos[beg][i].fi;
				int nm = pos[beg][i].sc;
				for(int j=nm+1;j<vi[id].size();j++){
					int cur = vi[id][j];
					pre[cur] = -1;
				}
			}
		}
		end2:;
		if(answer) continue;
		puts("Robot");
	}
}