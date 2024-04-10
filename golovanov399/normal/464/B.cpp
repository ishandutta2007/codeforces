#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define float long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

bool used[8];
vector<vector<int> > a(8, vector<int>(3));

void iscube(){
    int x[3];
    x[0] = x[1] = x[2] = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 3; j++){
            x[j] += a[i][j];
        }
    }
    for (int i = 0; i < 3; i++){
        if (x[i] % 4 != 0) return; else x[i] /= 4;
    }
    vector<int> q(8, -1);
    for (int i = 0; i < 8; i++){
        if (q[i] == -1){
            int j = i + 1;
            while (j < 8 && (q[j] != -1 || (a[i][0] + a[j][0] != x[0]) || (a[i][1] + a[j][1] != x[1]) || (a[i][2] + a[j][2] != x[2]))) j++;
            if (j == 8) return;
            q[i] = j;
            q[j] = i;
        }
    }
    vector<LL> d(8, 0);
    for (int i = 1; i < 8; i++){
        for (int j = 0; j < 3; j++){
            d[i] += 1ll * (a[i][j] - a[0][j]) * (a[i][j] - a[0][j]);
        }
    }
    LL m = 1000000000000000;
    for (int i = 1; i < 8; i++){
        m = min(m, d[i]);
    }
    if (m == 0) return;
    vector<int> v;
    for (int i = 1; i < 8; i++) if (d[i] == m) v.pb(i);
    if (v.size() != 3) return;
    vector<LL> sq(3, 0);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            sq[i] += 1ll * (a[v[i]][j] - a[0][j]) * (a[v[(i + 1) % 3]][j] - a[0][j]);
        }
    }
    if (sq[0] != 0 || sq[1] != 0 || sq[2] != 0) return;
    v.clear();
    for (int i = 0; i < 8; i++) if (d[i] == m + m) v.pb(i);
    if (v.size() != 3) return;
    if (d[q[0]] != m + m + m) return;
    cout << "YES\n";
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 3; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    exit(0);
}

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    bool qw = false;
    for (int i = 0; i < 8; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (int i = 0; i < 8; i++) sort(a[i].begin(), a[i].end());
    int i = 7;
    while (i > 0){
        if (!qw){
            iscube();
        }
        if (!next_permutation(a[i].begin(), a[i].end())){
            i--;
            qw = true;
        } else {
            i = 7;
            qw = false;
        }
    }
    cout << "NO\n";
    
    return 0;
}