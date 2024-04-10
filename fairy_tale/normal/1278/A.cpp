#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

int d[30];

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s, p;
        cin >> p >> s;
        int n = s.size(), m = p.size();
        bool vv = 0;
        for(int i = 0;i + m <= n; ++i) {
            memset(d, 0, sizeof(d));
            for(auto e:p) d[e - 'a']++;
            for(int j = 0;j < m; ++j) d[s[i + j] - 'a']--;
            bool fg = 0;
            for(int j = 0;j < 26; ++j) {
                if(d[j]) fg = 1;
            }
            if(!fg) vv = 1;
        }
        if(vv) puts("YES");
        else puts("NO");
    }

    return 0;
}