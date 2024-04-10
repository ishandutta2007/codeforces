#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

vector<pair<int, int> > ans;
int a[30][30], b[30][30];

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> cn(1000, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            cn[a[i][j]]++;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> b[i][j];
            cn[b[i][j]]--;
        }
    }
    for (int i = 0; i < 1000; i++) if (cn[i] != 0){
        cout << "-1\n";
        return 0;
    }
    if (n == 1){
        int i = 0;
        while (a[0][i] == b[0][i]) i++;
        int j = m - 1;
        while (a[0][j] == b[0][j]) j--;
        if (a[0][i] == b[0][j]){
            for (int ij = i; ij < j; ij++){
                if (a[0][ij + 1] != b[0][ij]){
                    cout << "-1\n";
                    return 0;
                }
            }
            cout << j - i << "\n";
            for (int ij = i; ij <= j; ij++){
                cout << 1 << " " << ij + 1 << "\n";
            }
        } else
        if (a[0][j] == b[0][i]){
            for (int ij = i; ij < j; ij++){
                if (a[0][ij] != b[0][ij + 1]){
                    cout << "-1\n";
                    return 0;
                }
            }           
            cout << j - i << "\n";
            for (int ij = j; ij >= i; ij--){
                cout << 1 << " " << ij + 1 << "\n";
            }
        } else {
            cout << "-1\n";
        }
    } else
    if (m == 1){
        int i = 0;
        while (a[i][0] == b[i][0]) i++;
        int j = n - 1;
        while (a[j][0] == b[j][0]) j--;
        if (a[i][0] == b[j][0]){
            for (int ij = i; ij < j; ij++){
                if (a[ij + 1][0] != b[ij][0]){
                    cout << "-1\n";
                    return 0;
                }
            }
            cout << j - i << "\n";
            for (int ij = i; ij <= j; ij++){
                cout << ij + 1 << " " << 1 << "\n";
            }
        } else
        if (a[j][0] == b[i][0]){
            for (int ij = i; ij < j; ij++){
                if (a[ij][0] != b[ij + 1][0]){
                    cout << "-1\n";
                    return 0;
                }
            }           
            cout << j - i << "\n";
            for (int ij = j; ij >= i; ij--){
                cout << ij + 1 << " " << 1 << "\n";
            }
        } else {
            cout << "-1\n";
        }   
    } else {
        vector<pair<pair<int, int>, pair<int, int> > > q;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int x = i, y = j;
                while (a[x][y] != b[i][j]){
                    y++;
                    if (y == m){
                        x++;
                        y = 0;
                    }
                }
                while (y != j){
                    if (y < j){
                        q.pb(mp(mp(x, y), mp(0, 1)));
                        swap(a[x][y], a[x][y + 1]);
                        y++;
                    } else {
                        q.pb(mp(mp(x, y), mp(0, -1)));
                        swap(a[x][y], a[x][y - 1]);
                        y--;
                    }
                }
                while (x > i){
                    q.pb(mp(mp(x, y), mp(-1, 0)));
                    swap(a[x][y], a[x - 1][y]);
                    x--;
                }
            }
        }
        int x = n - 1, y = m - 1;
        ans.pb(mp(x, y));
        for (int i = 0; i < q.size(); i++){
            if (q[i].y.x == 0){
                if (q[i].x.x == x){
                    if (q[i].x.y == y){
                        y += q[i].y.y;
                        ans.pb(mp(x, y));
                    } else
                    if (q[i].x.y + q[i].y.y == y){
                        y -= q[i].y.y;
                        ans.pb(mp(x, y));
                    } else {
                        if (x > 0){
                            int xx = x, yy = y;
                            xx--;
                            ans.pb(mp(xx, yy));
                            while (yy != q[i].x.y){
                                if (yy > q[i].x.y){
                                    yy--;
                                } else {
                                    yy++;
                                }
                                ans.pb(mp(xx, yy));
                            }
                            ans.pb(q[i].x);
                            ans.pb(mp(q[i].x.x + q[i].y.x, q[i].x.y + q[i].y.y));
                            ans.pb(mp(xx, yy));
                            while (yy != y){
                                if (yy > y){
                                    yy--;
                                } else {
                                    yy++;
                                }
                                ans.pb(mp(xx, yy));
                            }
                            xx++;
                            ans.pb(mp(xx, yy));
                        } else {
                            int xx = x, yy = y;
                            xx++;
                            ans.pb(mp(xx, yy));
                            while (yy != q[i].x.y){
                                if (yy > q[i].x.y){
                                    yy--;
                                } else {
                                    yy++;
                                }
                                ans.pb(mp(xx, yy));
                            }
                            ans.pb(q[i].x);
                            ans.pb(mp(q[i].x.x + q[i].y.x, q[i].x.y + q[i].y.y));
                            ans.pb(mp(xx, yy));
                            while (yy != y){
                                if (yy > y){
                                    yy--;
                                } else {
                                    yy++;
                                }
                                ans.pb(mp(xx, yy));
                            }
                            xx--;
                            ans.pb(mp(xx, yy));                         
                        }
                    }
                } else {
                    int xx = x, yy = y;
                    while (yy != q[i].x.y){
                        if (yy > q[i].x.y){
                            yy--;
                        } else {
                            yy++;
                        }
                        ans.pb(mp(xx, yy));
                    }
                    if (xx < q[i].x.x){
                        while (xx < q[i].x.x - 1){
                            xx++;
                            ans.pb(mp(xx, yy));
                        }
                        ans.pb(mp(q[i].x.x, q[i].x.y));
                        ans.pb(mp(q[i].x.x + q[i].y.x, q[i].x.y + q[i].y.y));
                        ans.pb(mp(xx, yy));
                        while (xx > x){
                            xx--;
                            ans.pb(mp(xx, yy));
                        }
                    } else {
                        while (xx > q[i].x.x + 1){
                            xx--;
                            ans.pb(mp(xx, yy));
                        }
                        ans.pb(mp(q[i].x.x, q[i].x.y));
                        ans.pb(mp(q[i].x.x + q[i].y.x, q[i].x.y + q[i].y.y));
                        ans.pb(mp(xx, yy));
                        while (xx < x){
                            xx++;
                            ans.pb(mp(xx, yy));
                        }                   
                    }
                    while (yy != y){
                        if (yy > y){
                            yy--;
                        } else {
                            yy++;
                        }
                        ans.pb(mp(xx, yy));
                    }
                }
            } else {
                if (q[i].x.y == y){
                    if (q[i].x.x == x){
                        x += q[i].y.x;
                        ans.pb(mp(x, y));
                    } else
                    if (q[i].x.x + q[i].y.x == x){
                        x -= q[i].y.x;
                        ans.pb(mp(x, y));
                    } else {
                        if (y > 0){
                            int xx = x, yy = y;
                            yy--;
                            ans.pb(mp(xx, yy));
                            while (xx != q[i].x.x){
                                if (xx > q[i].x.x){
                                    xx--;
                                } else {
                                    xx++;
                                }
                                ans.pb(mp(xx, yy));
                            }
                            ans.pb(q[i].x);
                            ans.pb(mp(q[i].x.x + q[i].y.x, q[i].x.y + q[i].y.y));
                            ans.pb(mp(xx, yy));
                            while (xx != x){
                                if (xx > x){
                                    xx--;
                                } else {
                                    xx++;
                                }
                                ans.pb(mp(xx, yy));
                            }
                            yy++;
                            ans.pb(mp(xx, yy));
                        } else {
                            int xx = x, yy = y;
                            yy++;
                            ans.pb(mp(xx, yy));
                            while (xx != q[i].x.x){
                                if (xx > q[i].x.x){
                                    xx--;
                                } else {
                                    xx++;
                                }
                                ans.pb(mp(xx, yy));
                            }
                            ans.pb(q[i].x);
                            ans.pb(mp(q[i].x.x + q[i].y.x, q[i].x.y + q[i].y.y));
                            ans.pb(mp(xx, yy));
                            while (xx != x){
                                if (xx > x){
                                    xx--;
                                } else {
                                    xx++;
                                }
                                ans.pb(mp(xx, yy));
                            }
                            yy--;
                            ans.pb(mp(xx, yy));                         
                        }
                    }
                } else {
                    int xx = x, yy = y;
                    while (xx != q[i].x.x){
                        if (xx > q[i].x.x){
                            xx--;
                        } else {
                            xx++;
                        }
                        ans.pb(mp(xx, yy));
                    }
                    if (yy < q[i].x.y){
                        while (yy < q[i].x.y - 1){
                            yy++;
                            ans.pb(mp(xx, yy));
                        }
                        ans.pb(mp(q[i].x.x, q[i].x.y));
                        ans.pb(mp(q[i].x.x + q[i].y.x, q[i].x.y + q[i].y.y));
                        ans.pb(mp(xx, yy));
                        while (yy > y){
                            yy--;
                            ans.pb(mp(xx, yy));
                        }
                    } else {
                        while (yy > q[i].x.y + 1){
                            yy--;
                            ans.pb(mp(xx, yy));
                        }
                        ans.pb(mp(q[i].x.x, q[i].x.y));
                        ans.pb(mp(q[i].x.x + q[i].y.x, q[i].x.y + q[i].y.y));
                        ans.pb(mp(xx, yy));
                        while (yy < y){
                            yy++;
                            ans.pb(mp(xx, yy));
                        }                   
                    }
                    while (xx != x){
                        if (xx > x){
                            xx--;
                        } else {
                            xx++;
                        }
                        ans.pb(mp(xx, yy));
                    }
                }               
            }
        }
        cout << ans.size() - 1 << "\n";
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i].x + 1 << " " << ans[i].y + 1 << "\n";
        }
    }

    return 0;
}