#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

const int xx[4] = {-1, 0, 1, 0};
const int yy[4] = {0, 1, 0, -1};
const int N = 1111;
string a[N];

int dst[3][N][N];
int n, m;

int main(){

    n = nxt(), m = nxt();
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int cl = 0; cl < 3; cl++){
        deque<pair<int, int>> q;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (a[i][j] == '1' + cl){
                    dst[cl][i][j] = 0;
                    q.push_back({i, j});
                } else
                    dst[cl][i][j] = -1;
            }
        }
        while (!q.empty()){
            auto p = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++){
                if (p.x + xx[i] >= 0 && p.x + xx[i] < n && p.y + yy[i] >= 0 && p.y + yy[i] < m && dst[cl][p.x + xx[i]][p.y + yy[i]] == -1 && a[p.x + xx[i]][p.y + yy[i]] != '#'){
                    if (a[p.x + xx[i]][p.y + yy[i]] == '.'){
                        q.push_back({p.x + xx[i], p.y + yy[i]});
                        dst[cl][p.x + xx[i]][p.y + yy[i]] = dst[cl][p.x][p.y] + 1;
                    } else {
                        q.push_front({p.x + xx[i], p.y + yy[i]});
                        dst[cl][p.x + xx[i]][p.y + yy[i]] = dst[cl][p.x][p.y];
                    }
                }
            }
        }
    }

    // for (int cl = 0; cl < 3; cl++){
    //  for (int i = 0; i < n; i++){
    //      for (int j = 0; j < m; j++)
    //          if (dst[cl][i][j] == -1)
    //              cerr << '#';
    //          else
    //              cerr << dst[cl][i][j];
    //      cerr << "\n";
    //  }
    //  cerr << "\n";
    // }
    // cerr << "\n";

    int ans = INT_MAX;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dst[0][i][j] != -1 && dst[1][i][j] != -1 && dst[2][i][j] != -1)
                ans = min(ans, dst[0][i][j] + dst[1][i][j] + dst[2][i][j] - (a[i][j] == '.' ? 2 : 0));
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";

    return 0;
}