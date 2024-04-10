#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;

string s,ss;
int m,x,y,z;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s >> m;
    while (m--) {
        cin >> x >> y >> z;
        --x; --y;
        z %= (y - x + 1);
        ss = s.substr(y - z + 1, z);
        s.erase(y - z + 1, z);
        s.insert(x, ss);
    }
    cout << s;

    return 0;
}