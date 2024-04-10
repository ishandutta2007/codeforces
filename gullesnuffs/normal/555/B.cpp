#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll l[200005], r[200005];
ll a[200005];
pair<ll, pair<ll, ll> > p[200005];
map<ll, vector<ll> > M;
int ans[200005];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	rep(i,0,n)
		scanf("%I64d%I64d", l+i, r+i);
	rep(i,0,n-1){
		ll x=l[i+1]-r[i];
		ll y=r[i+1]-l[i];
		p[i]=make_pair(y, make_pair(x, i));
	}
	rep(i,0,m){
		scanf("%I64d", a+i);
		M[a[i]].push_back(i);
	}
	sort(p, p+(n-1));
	rep(i,0,n-1){
		ll v=p[i].second.first;
		ll ind=p[i].second.second;
		auto it=M.lower_bound(v);
		if(it == M.end()){
			puts("No");
			return 0;
		}
		if(it->first > p[i].first){
			puts("No");
			return 0;
		}
		ans[ind]=it->second.back();
		it->second.pop_back();
		if(it->second.empty())
			M.erase(it);
	}
	puts("Yes");
	rep(i,0,n-1){
		printf("%d ", ans[i]+1);
	}
	printf("\n");
}