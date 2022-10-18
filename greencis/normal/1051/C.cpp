#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[105], c[105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], ++c[a[i]];
    int cnt = 0;
    int idx = -1;
    for (int i = 0; i <= 100; ++i)
        cnt += c[i] == 1, idx = (c[i] >= 3 ? i : idx);
    if (cnt % 2) {
        if (idx == -1) { cout << "NO"; return 0; }
        for (int i = 0; i < n; ++i) {
            if (a[i] == idx) {
                --c[a[i]];
                ++c[101];
                a[i] = 101;
                break;
            }
        }++cnt;
    }
   // else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (a[i] == 101)
                cout << 'B';
            else if (a[i] == idx)
                cout << 'A';
            else {
                cout << (c[a[i]] == 1 && cnt % 2 == 0 ? 'A' : 'B');
            if (c[a[i]] == 1) --cnt;}
        }
    //}
}