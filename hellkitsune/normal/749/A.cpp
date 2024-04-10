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
    if (n % 2 == 1) {
        n -= 3;
        ans.pb(3);
    }
    while (n) {
        n -= 2;
        ans.pb(2);
    }
    cout << int(ans.size()) << endl;
    for (int x : ans) {
        printf("%d ", x);
    }
    cout << endl;
    return 0;
}