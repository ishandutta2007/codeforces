#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;
const long long mod = 998244353;

using namespace std;

void upd(int &x, int y)
{
        x += y;
        if(x >= mod){
                x -= mod;
        }
}

string s;
int l[2];
int r[2];
int a[N][2];

bool dfs(int x, int y, int g)
{
        if(x < l[y]){
                return true;
        }
        if(a[x][y] != -1){
                if(a[x][y] != g){
                        return false;
                }
                return true;
        }
        a[x][y] = g;
        bool res = dfs(r[y] - x + l[y], y, g);
        if(s[x] != '?'){
                res &= dfs(x, y ^ 1, g ^ (s[x] - '0'));
        }
        return res;
}

int solve(int x)
{
        for(int i = 0; i < s.size(); i++){
                a[i][0] = a[i][1] = -1;
        }
        l[0] = 0;
        r[0] = s.size() - 1;
        l[1] = x;
        r[1] = s.size() - 1;
        int res = 1;
        for(int i = 0; i <= x; i++){
                if(s[i] != '?'){
                        res &= dfs(i, 0, (s[i] - '0') ^ (i == x));
                }
                if(i < x){
                        a[i][1] = 0;
                }
        }
        dfs(x, 1, 1);
        for(int i = 0; i < s.size(); i++){
                if(a[i][0] == -1){
                        upd(res, res);
                        dfs(i, 0, 0);
                }
                if(a[i][1] == -1){
                        upd(res, res);
                        dfs(i, 1, 1);
                }
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> s;
        int res = 0;
        for(int i = 1; i < s.size(); i++){
                upd(res, solve(i));
        }
        cout << res << "\n";
}