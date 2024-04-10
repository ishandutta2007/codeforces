#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    int cnt = 0;
    int good = 0;
    cin >> s;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '1')
            good = 1;
        if (good)
            cnt += s[i] == '0';
    }
    cout << (cnt >= 6 ? "yes" : "no");

    return 0;
}