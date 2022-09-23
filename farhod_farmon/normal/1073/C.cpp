#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

int n;
int dx[N];
int dy[N];
string s;

bool can(int x, int y, int m)
{
        if(m == 0){
                return dx[n] == x && dy[n] == y;
        }
        for(int i = 1; i + m - 1 <= n; i++){
                int curx = dx[i - 1], cury = dy[i - 1];
                curx += dx[n] - dx[i + m - 1];
                cury += dy[n] - dy[i + m - 1];
                int dif = abs(curx - x) + abs(cury - y);
                if(dif <= m && (m - dif) % 2 == 0){
                        return true;
                }
        }
        return false;
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        int x, y;
        cin >> n >> s >> x >> y;
        for(int i = 0; i < n; i++){
                dx[i + 1] = dx[i];
                dy[i + 1] = dy[i];
                if(s[i] == 'U') dy[i + 1]++;
                if(s[i] == 'D') dy[i + 1]--;
                if(s[i] == 'L') dx[i + 1]--;
                if(s[i] == 'R') dx[i + 1]++;
        }
        int l = 0, r = n + 1;
        while(l < r){
                int m = (l + r) / 2;
                if(can(x, y, m)){
                        r = m;
                }
                else{
                        l = m + 1;
                }
        }
        if(l == n + 1){
                cout << -1 << "\n";
        }
        else{
                cout << l << "\n";
        }
}