                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             #include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a, b, c, n;

int main() {
    scanf("%d%d%d%d", &a, &b, &c, &n);
    int ans = 0;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        if (x > b && x < c) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}