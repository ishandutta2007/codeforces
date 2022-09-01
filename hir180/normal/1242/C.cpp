#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
const ll mod = 1000000007;
typedef pair<ll,int> P;
int n,m;
vector<int>edge[100005];
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)

vector<P>vec;
bool dp[1<<15];
int pre[1<<15];
P beg[1<<15];
ll sum,S[20];
int main(){
	scanf("%d",&n);
	rep(i,n){
		int k; scanf("%d",&k);
		rep(j,k){
			int x; scanf("%d",&x); sum+=x; S[i]+=x;
			vec.pb(P(1LL*x,i));
		}
	}
	if(sum%n != 0){
		puts("No"); return 0;
	}
	sum /= n; //cout << sum << endl;
	sort(vec.begin(),vec.end());
	rep(i,(1<<n)) beg[i]=P(-1e18,-1);
	rep(i,vec.size()){
		P cur = vec[i];
		int see = 0;
		//cout << cur.fi << " " << cur.sc << endl;
		do{
			if((see & (1<<cur.sc)) > 0) goto fail;
			see |= (1<<cur.sc);
			ll go = cur.fi + sum - S[cur.sc];
			//cout << go << "  " << cur.sc << endl;
			int id = lower_bound(vec.begin(),vec.end(),P(go,-1))-vec.begin();
			if(id < vec.size() && vec[id].fi == go){
				cur = vec[id];
			}
			else goto fail;
			//cout << cur.sc << " " << vec[i].sc << endl;
		}while(cur.sc != vec[i].sc);
		if(cur.fi != vec[i].fi) goto fail;
		//cout << see << " " << vec[i].fi << " " << vec[i].sc << endl;
		beg[see] = vec[i]; fail:;
	}
	dp[0] = 1;
	for(int i=1;i<(1<<n);i++){
		if(beg[i].sc < 0) continue;
		int M = (1<<n)-1-i;
		int B = M;
		while(1){
			if(dp[M]){
				dp[M+i] = true;
				pre[M+i] = M;
			}
			if(M == 0) break;
			M = (M-1) & B;
		}
	}
	if(!dp[(1<<n)-1]){
		puts("No");
	}
	else{
		puts("Yes");
		int cur = (1<<n)-1;
		vector<int>ans;
		while(cur){
			ans.pb(cur-pre[cur]);
			cur = pre[cur];
		}
		ll val[20],idx[20];
		rep(i,ans.size()){
			P cur = beg[ans[i]];
			do{
				val[cur.sc] = cur.fi;
				ll go = cur.fi + sum - S[cur.sc];
				int id = lower_bound(vec.begin(),vec.end(),P(go,-1))-vec.begin();
				if(id < vec.size() && vec[id].fi == go){
					idx[vec[id].sc] = cur.sc;
					cur = vec[id];
				}
			}while(cur.sc != beg[ans[i]].sc);
		}
		rep(i,n) cout << val[i] << " " << idx[i]+1 << endl;
	}
}