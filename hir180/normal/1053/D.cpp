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
int n,C[2000005];
int go[2000005];
vector<int>cnt[2000005];
vector<P>vecc[600005];;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=2000000;i++){
		if(go[i]) continue;
		go[i] = i;
		for(int j=i+i;j<=2000000;j+=i){
			go[j] = i;
		}
	}
	for(int i=1;i<=n;i++){
		int w;
		scanf("%d",&w);
		C[w]++;
	}
	int num = 0;
	bool ok = 0;
	for(int i=2000000;i>=2;i--){
		if(C[i] == 0) continue;
		if(C[i] == 1){
			if(cnt[i].empty()){
				cnt[i].pb(1);
				vecc[num++].pb(mp(i,1));
			}
			else{
				int cur = i-1;
    			vector<int>vec;
    			while(cur > 1){
    				vec.pb(go[cur]);
    				cur /= go[cur];
    			}
    			SORT(vec);
    			cur = -1;
    			int ccnt = 0;
    			for(int j=0;j<vec.size();j++){
    				if(j == 0){
    					cur = vec[j];
    					ccnt = 1;
    					continue;
    				}
    				if(cur != vec[j]){
    					cnt[cur].pb(ccnt);
    					vecc[num].pb(mp(cur,ccnt));
    					cur = vec[j];
    					ccnt = 1;
    				}
    				else ccnt++;
    			}
    			if(cur > 1){
        			cnt[cur].pb(ccnt);
        			vecc[num++].pb(mp(cur,ccnt));
    			}else num++;
			}
		}
		else {
			if(C[i] > 2) ok = 1;
			cnt[i].pb(1);
			vecc[num++].pb(mp(i,1));
			int cur = i-1;
			vector<int>vec;
			while(cur > 1){
				vec.pb(go[cur]);
				cur /= go[cur];
			}
			SORT(vec);
			cur = -1;
			int ccnt = 0;
			for(int j=0;j<vec.size();j++){
				if(j == 0){
					cur = vec[j];
					ccnt = 1;
					continue;
				}
				if(cur != vec[j]){
					cnt[cur].pb(ccnt);
					vecc[num].pb(mp(cur,ccnt));
					cur = vec[j];
					ccnt = 1;
				}
				else ccnt++;
			}
			if(cur > 1){
    			cnt[cur].pb(ccnt);
    			vecc[num++].pb(mp(cur,ccnt));
			}else num++;
		}
	}
	for(int i=2;i<=2000000;i++){
		SORT(cnt[i]);
		reverse(cnt[i].begin(),cnt[i].end());
	}
	for(int i=0;i<num;i++){
		for(int j=0;j<vecc[i].size();j++){
			int A = vecc[i][j].fi, B = vecc[i][j].sc;
			if(cnt[A].size() == 1 || cnt[A][1] < B) goto fail;
		}
		ok = 1; break;
		fail:;
	}
	ll ans = 1;
	for(int i=2;i<=2000000;i++){
		if(cnt[i].size()) rep(j,cnt[i][0]) ans = ans*1LL*i%mod;
	}
	if(ok) ans = (ans+1LL)%mod;
	cout<<ans<<endl;
}