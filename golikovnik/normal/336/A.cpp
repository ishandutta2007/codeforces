#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'
#define X first
#define Y second

int sgn(int n) {
    return (n > 0) ? 1 : -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int x, y;
    cin >> x >> y;
    bool pos = (sgn(x) * sgn(y)) > 0;
    int k = pos ? x + y : y - x;
    vector<pii> res = {mp(0, k), mp((pos ? k : -k), 0)};
    sort(all(res));
    cout << res[0].X << " " << res[0].Y << " " << res[1].X << " " << res[1].Y << endl;
    return 0;
}