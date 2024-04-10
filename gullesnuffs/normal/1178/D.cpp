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

bool isPrime(int x) {
    for (int i = 2; i*i <= x; i++)
        if (x%i == 0)
            return 0;
    return 1;
}

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    rep(i,0,n) {
        edges.emplace_back(i, (i+1)%n);
    }
    int j = 0;
    while (!isPrime(sz(edges))) {
        edges.emplace_back(j, j+(n/2));
        j++;
    }
    cout << sz(edges) << endl;
    for (auto it : edges) {
        assert(it.second < n);
        cout << it.first+1 << " " << it.second+1 << endl;
    }
}