#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef pair<P,int> P1;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)

int n;
ll pp,a[100005],ans[100005];
priority_queue<P1,vector<P1>,greater<P1>>que;
deque<int>ln;
set<int>zan;

int main(){
	scanf("%d%lld",&n,&pp);
	rep(i,n){
		scanf("%lld",&a[i]);
		que.push(mp(P(a[i],1),i));
	}
	while(!que.empty()){
		P1 p = que.top(); que.pop();
		ll tm = p.fi.fi;
		int ty = p.fi.sc;
		int id = p.sc;
		if(ty == 1){
			if(ln.empty() || ln[ln.size()-1] > id){
				if(ln.empty()){
					ans[id] = tm+pp;
					que.push(mp(P(ans[id],2),id));
				}
				else{
					ans[id] = ans[ln[ln.size()-1]]+pp;
					que.push(mp(P(ans[id],2),id));
				}
				ln.pb(id);
			}
			else{
				zan.insert(id);
			}
		}
		else{
		    ln.pop_front();
			if(!zan.empty()){
				int id = *zan.begin();
				if(ln.empty() || ln[ln.size()-1] > id){
					if(ln.empty()){
						ans[id] = tm+pp;
						que.push(mp(P(ans[id],2),id));
					}
					else{
						ans[id] = ans[ln[ln.size()-1]]+pp;
						que.push(mp(P(ans[id],2),id));
					}
					ln.pb(id);
					zan.erase(zan.begin());
				}
			}
		}
	}
	rep(i,n) cout << ans[i] << '\n';
}