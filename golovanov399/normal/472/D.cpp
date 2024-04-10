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

int dist[2000][2000];
int ar[2000][2000];

int main(){

    int n;
    scanf("%d", &n);
    vector<pair<int, pair<int, int> > > a;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            scanf("%d", &x);
            ar[i][j] = x;
            if (i <= j)
                a.pb(mp(x, mp(i, j)));
            else if (x != ar[j][i]){
                cout << "NO\n";
                return 0;
            }
        }
    }
    sort(a.begin(), a.end());
    vector<int> clr(n);
    vector<vector<int> > c(n);
    for (int i = 0; i < n; i++) c[i].pb(i);
    for (int i = 0; i < n; i++) clr[i] = i;
    for (int i = 0; i < a.size(); i++){
        int x = a[i].y.x, y = a[i].y.y, d = a[i].x;
        if (clr[x] == clr[y]){
            if (dist[x][y] != d){
                cout << "NO\n";
                return 0;
            }
        } else {
            if (d == 0){
                cout << "NO\n";
                return 0;
            }
            int X = clr[x], Y = clr[y];
            if (c[X].size() > c[Y].size()){
                swap(x, y);
                swap(X, Y);
            }
            for (int j = 0; j < c[X].size(); j++){
                for (int ij = 0; ij < c[Y].size(); ij++){
                    dist[c[X][j]][c[Y][ij]] = dist[c[Y][ij]][c[X][j]] = dist[c[X][j]][x] + d + dist[y][c[Y][ij]];
                }
            }
            for (int j = 0; j < c[Y].size(); j++){
                clr[c[Y][j]] = X;
                c[X].pb(c[Y][j]);
            }
//          c[Y].clear();
        }
    }
    cout << "YES\n";

    return 0;
}