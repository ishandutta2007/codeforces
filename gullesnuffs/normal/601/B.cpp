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

int a[100005];
int b[100005];
pair<int, int> order[100005];
int L[100005], R[100005];

int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	rep(i,0,n)
		scanf("%d", a+i);
	rep(i,0,n-1){
		b[i]=abs(a[i+1]-a[i]);
		order[i]=make_pair(b[i], i);
	}
	sort(order, order+(n-1));
	set<int> S;
	S.insert(-1);
	S.insert(n);
	rrep(j,n-1,0){
		int pos=order[j].second;
		auto it=S.lower_bound(pos);
		R[j]=*it;
		--it;
		L[j]=*it;
		S.insert(pos);
	}
	rep(i,0,q){
		int l, r;
		scanf("%d%d", &l, &r);
		--l;--r;
		ll ans=0;
		rep(j,0,n-1){
			int pos=order[j].second;
			if(pos < l)
				continue;
			if(pos >= r)
				continue;
			ll myl=max(l-1, L[j]);
			ll myr=min(r, R[j]);
			myl=pos-myl;
			myr=myr-pos;
			ans += myl*myr*order[j].first;
		}
		printf("%I64d\n", ans);
	}
}