#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        string s;
        cin >> s;
        int n = s.size();
        s = "#" + s;
        vector < int > d(n + 1);
        d[0] = 1;
        for(int i = 1; i <= n; i++){
                if(s[i] == 'm' || s[i] == 'w'){
                        cout << 0 << "\n";
                        return 0;
                }
                d[i] = d[i - 1];
                if(s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u')){
                        d[i] += d[i - 2];
                        if(d[i] >= mod){
                                d[i] -= mod;
                        }
                }
        }
        cout << d[n] << "\n";
}