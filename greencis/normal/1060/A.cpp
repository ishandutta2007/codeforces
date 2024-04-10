#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int cnt[10];

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; s[i]; ++i)
        ++cnt[s[i] - '0'];
    cout << min(cnt[8], n / 11);
}