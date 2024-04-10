#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 500500;
const long long mod = 998244353;

using namespace std;

int n;
int l[N];
int r[N];
string s;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> s;
        n = s.size();
        s = "#" + s;
        for(int i = 1; i <= n; i++){
                l[i] = l[i - 1];
                if(l[i] > 1 && s[i] == '|'){
                        l[i] += 1;
                }
                if(l[i] == 1 && s[i] == ':'){
                        l[i] = 2;
                }
                if(l[i] == 0 && s[i] == '['){
                        l[i] = 1;
                }
        }
        for(int i = n; i >= 1;i--){
                r[i] = r[i + 1];
                if(r[i] > 1 && s[i] == '|'){
                        r[i] += 1;
                }
                if(r[i] == 1 && s[i] == ':'){
                        r[i] = 2;
                }
                if(r[i] == 0 && s[i] == ']'){
                        r[i] = 1;
                }
        }
        int res = -1;
        for(int i = 1; i <= n; i++){
                if(l[i] > 1 && r[i + 1] > 1){
                        res = max(res, l[i] + r[i + 1]);
                }
        }
        cout << res << "\n";
}