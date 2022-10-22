#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

map<vi, int> cache;

int grundy(vector<int> a) {
    if (cache.count(a))
        return cache[a];
    set<int> canReach;
    rep(i,0,(1<<(sz(a)))) {
        if (__builtin_popcount(i) != sz(a)/2)
            continue;
        vector<int> b = a;
        bool ok = 1;
        rep(j,0,(sz(a))) {
            if (i&(1<<j)) {
                --b[j];
                if (b[j] < 0)
                    ok = 0;
            }
        }
        if (!ok)
            continue;
        while (true) {
            int g = grundy(b);
            canReach.insert(g);
            bool ok = false;
            rep(j,0,(sz(a))) {
                if (i&(1<<j)) {
                    --b[j];
                    if (b[j] < 0)
                        b[j] = a[j]-1;
                    else {
                        ok = true;
                        break;
                    }
                }
            }
            if (!ok)
                break;
        }
    }
    int i;
    for (i = 0; canReach.count(i); ++i);
    cache[a] = i;
    return i;
}

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n)
        cin >> a[i];
    sort(all(a));
    if (a[n/2] == a[0])
        cout << "Bob" << endl;
    else
        cout << "Alice" << endl;
    /*rep(i,1,100)
    rep(j,1,i+1)
    rep(k,1,j+1)
    rep(l,1,k+1)
    rep(m,1,l+1)
    rep(n,1,m+1) {
        if (!grundy({i,j,k,l,m,n})) {
            cout << i << " " << j << " " << k << " " << l << " " << m << " " << n << endl;
        }
    }*/
}