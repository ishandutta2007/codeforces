#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<int N>
struct fenwick_multiset {

    int s = 0, tree[N+1] = {};
    int size() const { return s; }
    
    // insert x into the set with multiplicity k
    void insert(int x, const int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    int index(int x) const {
        int i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    int count(int x) const {
        int y = x+1, i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(int x) const {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

const int N = 1e6+5;
fenwick_multiset<N> f;
vector<int> q[N];
int dp[N][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    for (int i = n-1; i >= 0; i--) {
        dp[i][0] = s[i] == '1' ? 0 : dp[i+1][0]+1;
        dp[i][1] = s[i] == '0' ? 0 : dp[i+1][1]+1;
        q[max(dp[i][0], dp[i][1])].pb(i);
        f.insert(i);
    }
    for (int i = 0; i < n; i++) {
        for (auto& x : q[i]) f.remove(x);
        int r = -1;
        for (int j = -inf; j < N; r++)
            j = f.get(f.index(j+i+1));
        cout << r << " ";
    }
}