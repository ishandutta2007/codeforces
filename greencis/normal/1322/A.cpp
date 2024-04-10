#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    int balance = 0;
    for (int i = 0; s[i]; ++i)
        balance += s[i] == '(' ? 1 : -1;
    if (balance) {
        cout << -1;
        return 0;
    }

    int last_time_0 = -1;
    int ans = 0;
    for (int i = 0; s[i]; ++i) {
        bool was_neg = balance < 0;
        balance += s[i] == '(' ? 1 : -1;
        if (balance == 0) {
            if (was_neg)
                ans += i - last_time_0;
            last_time_0 = i;
        }
    }
    cout << ans << endl;
}