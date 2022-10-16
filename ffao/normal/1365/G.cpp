#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

long long query(vi v) {
    if (v.empty()) return 0;
    cout << "? " << v.size();
    for (int x : v) cout << " " << x+1;
    cout << endl;
    long long r; cin >> r; return r;
}

vector<int> queries[13];
int cur[13];
vector<int> which[1000];
long long ans[13];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < 6; i++) cur[12-i]=1;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < 13; i++) {
            if (cur[i]) which[k].push_back(i);
            else queries[i].push_back(k);
        }
        next_permutation(cur,cur+13);
    }

    for (int i = 0; i < 13; i++) {
        ans[i] = query(queries[i]);
    }

    cout << "!";
    for (int i = 0; i < n; i++) {
        long long t = 0;
        for (int x : which[i]) t |= ans[x];
        cout << " " << t;
    }
    cout << endl;

    return 0;
}