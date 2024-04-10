#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int cnt[26];
int n, k;
string s;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i)
        ++cnt[s[i] - 'A'];
    int mn = 1e9;
    for (int i = 0; i < k; ++i)
        mn = min(mn, cnt[i]);
    cout << mn * k;
}