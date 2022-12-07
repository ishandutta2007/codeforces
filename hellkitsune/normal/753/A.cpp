#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ans.pb(i);
        n -= i;
    }
    ans.back() += n;
    cout << int(ans.size()) << endl;
    for (int x : ans) {
        printf("%d ", x);
    }
    puts("");
    return 0;
}