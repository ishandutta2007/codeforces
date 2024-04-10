//#pragma GCC optimize("O3")
//#pragma GCC target("sse4.1")
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = ((int)(n) - 1); i >= 0; --i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

void solve (int x1)
{
    int y1, x2, y2;
    cin >> y1 >> x2 >> y2;

    int ans = 2 * (abs(x1 - x2) + abs(y1 - y2)) + 4;
    ans += 2 * (((x2 == x1) || (y2 == y1)) ? 1 : 0);
    cout << ans << endl;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
        solve(n);
}