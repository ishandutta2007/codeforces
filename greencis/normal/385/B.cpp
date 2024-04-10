#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

string s;
int ans;

int main()
{
    cin >> s;
    int last = -1;
    for (int i = 0; i + 4 <= s.size(); ++i) {
        if (s[i] == 'b' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'r')
            ans += (s.size() - i - 3) * (i - last), last = i;
    }
    cout << ans;

    return 0;
}