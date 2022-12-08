#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<"@"<<__LINE__<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

struct UF {
	vi e;
    vi r;
	UF(int n) : e(n, -1), r(n) {
        rep(i,0,n) r[i] = i;
    }
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    int right(int x) { return r[find(x)]; }
	bool join(int a, int b) {
		a = find(a), b = find(b);
        int rr = r[b];
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
        r[a] = rr;
		return true;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    vector<pii> b;
    rep(i,0,n) b.emplace_back(-a[i],i);
    sort(all(b));
    vi ord(n);
    rep(i,0,n) ord[i] = b[i].second;
    int j = 0;
    UF uf(n);
    vector<bool> added(n);
    vector<int> ans(n);
    set<int> s;
    const int INFTY = 3*n;
    for(int i:ord) {
        while(j<n && a[ord[j]]*2>=a[i]) {
            int k = ord[j];
            int nr = (k+1)%n, nl = (k+n-1)%n;
            if(added[nr]) uf.join(k,nr);
            if(added[nl]) uf.join(nl,k);
            added[k] = true;
            ++j;
        }
        int x = (uf.right(i)-i+n)%n+1;
        if(uf.size(i)==n) {
            x = INFTY;
        }
        if(!s.empty()) {
            auto nxt = s.upper_bound(i);
            if(nxt==s.end()) nxt = s.begin();
            int j = *nxt;
            if((j-i+n)%n+1<=x) ans[i] = ans[j]+(j-i+n)%n;
            else ans[i] = x;
        }
        else ans[i] = x;
        s.insert(i);
    }
    rep(i,0,n) {
        if(ans[i]>=INFTY) cout<<"-1 ";
        else cout << ans[i]<<" ";
    }
    cout<<endl;
}