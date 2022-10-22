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

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main(){
	ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> segments;
    rep(i,0,m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (b < a)
            swap(a, b);
        segments.insert(make_pair(a, b));
    }
    set<int> checked;
    rep(i,1,n) {
        int g = gcd(i, n);
        if (checked.count(g))
            continue;
        checked.insert(g);
        set<pair<int, int>> rotated;
        for (const auto& seg : segments) {
            int a = (seg.first + i) % n;
            int b = (seg.second + i) % n;
            if (b < a)
                swap(a, b);
            rotated.insert(make_pair(a, b));
        }
        if (rotated == segments) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}