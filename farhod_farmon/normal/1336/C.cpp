#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3003;
const int mod = 998244353;

using namespace std;

void add(int &x, int y)
{
        x += y;
        if(x >= mod) x -= mod;
}

int n;
int d[N][N];
string s, t;

bool eq(int x, int y)
{
        if(t[y] == '#') return true;
        return s[x] == t[y];
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> s >> t;
        int m = t.size();
        while(t.size() < s.size()) t += "#";
        n = s.size();

        for(int i = n - 1; i >= 0; i--){
                d[i][i] = eq(0, i);
                for(int j = i; j < n; j++){
                        if(i - 1 >= 0 && eq(j - i + 1, i - 1)) add(d[i - 1][j], d[i][j]);
                        if(j + 1 < n && eq(j - i + 1, j + 1)) add(d[i][j + 1], d[i][j]);
                }
        }
        int res = 0;
        for(int i = m - 1; i < n; i++){
                add(res, d[0][i]);
        }
        add(res, res);
        cout << res << "\n";
}