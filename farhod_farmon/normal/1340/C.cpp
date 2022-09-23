#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 10001;
const int Q = 1001;

using namespace std;

int inf = 1e9;

int n, m;
int a[N];
int g, r;
int d[N][Q];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                cin >> a[i];
        }
        cin >> g >> r;
        sort(a + 1, a + m + 1);
        for(int i = 1; i <= m; i++){
                for(int j = 0; j <= g; j++){
                        d[i][j] = inf;
                }
        }
        vector < int > ord;
        ord.push_back(1);
        d[1][g] = -1;
        queue < pair < int, int > > q;
        int x, y, cur, ny;
        while(!ord.empty()){
                for(int x: ord){
                        if(d[x][0] == inf){
                                d[x][0] = d[x][g] + 1;
                                q.push({x, 0});
                        }
                }
                ord.clear();
                while(!q.empty()){
                        x = q.front().fi;
                        y = q.front().se;
                        q.pop();
                        cur = d[x][y];
                        ny = y + a[x + 1] - a[x];
                        if(x + 1 <= m && ny <= g && cur < d[x + 1][ny]){
                                //assert(d[x + 1][ny] == inf);
                                d[x + 1][ny] = cur;
                                q.push({x + 1, ny});
                        }
                        ny = y + a[x] - a[x - 1];
                        if(x - 1 >= 1 && ny <= g && cur < d[x - 1][ny]){
                                //assert(d[x - 1][ny] == inf);
                                d[x - 1][ny] = cur;
                                q.push({x - 1, ny});
                        }

                        if(y == g){
                                ord.push_back(x);
                        }
                }
        }
        int res = inf;
        for(int i = 0; i <= g; i++){
                if(d[m][i] == inf){
                        continue;
                }
                res = min(res, d[m][i] * (r + g) + i);
        }
        if(res == inf){
                res = -1;
        }
        cout << res << "\n";
}