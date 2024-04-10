#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

char z[4];
int cnt[256];

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '!')
            z[i % 4] = s[i];
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '!')
            ++cnt[z[i % 4]];
    }
    cout << cnt['R'] << " " << cnt['B'] << " " << cnt['Y'] << " " << cnt['G'] << endl;

    return 0;
}