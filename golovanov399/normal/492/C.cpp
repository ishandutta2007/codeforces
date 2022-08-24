#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n, r, avg;
    cin >> n >> r >> avg;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].y >> a[i].x;
    sort(all(a));
    LL need = 1ll * avg * n;
    LL s = 0;
    for (int i = 0; i < n; i++)
        s += a[i].y;
    LL ans = 0;
    int i = 0;
    while (i < n && s < need){
        if (r - a[i].y < need - s){
            s += r - a[i].y;
            ans += 1ll * a[i].x * (r - a[i].y);
        } else {
            ans += 1ll * a[i].x * (need - s);
            s = need;
        }
        i++;
    }
    cout << ans << "\n";

    return 0;
}