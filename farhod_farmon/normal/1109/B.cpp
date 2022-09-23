#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100010;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int c[1 << 20][2];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        string s, t = "";
        cin >> s;
        int res = 0;
        for(int i = 1; i < s.size(); i++){
                if((int)(s.size()) % 2 && i == (int)s.size() / 2){
                        continue;
                }
                if(s[i] != s[0]){
                        res = 2;
                        break;
                }
        }
        if(res == 0){
                cout << "Impossible" << "\n";
                return 0;
        }
        for(int i = 1; i < s.size(); i++){
                t = "";
                for(int j = i; j < s.size(); j++){
                       t += s[j];
                }
                for(int j = 0; j < i; j++){
                        t += s[j];
                }
                bool ok = (s != t);
                for(int j = 0; j < t.size() / 2; j++){
                        if(t[j] != t[t.size() - j - 1]){
                                ok = false;
                        }
                }
                if(ok){
                        res = 1;
                }
        }
        cout << res << "\n";
}