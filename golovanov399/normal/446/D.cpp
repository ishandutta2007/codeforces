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
#define double long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

vector<int> ar, tr;
vector<vector<int> > a;
vector<vector<double> > p;

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    cout << setprecision(10) << fixed;
    int n, m, k;
    cin >> n >> m >> k;
    tr.resize(n);
    for (int i = 0; i < n; i++) cin >> tr[i];
    a.resize(n);
    for (int i = 0; i < n; i++){
        a[i].resize(n);
    }
    vector<int> d(n, 0);
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x][y]++;
        a[y][x]++;
        d[x]++;
        d[y]++;
    }
    ar.resize(n);
    int c = 0, cc = 0;
    for (int i = 0; i < n; i++){
        if (tr[i] == 0) ar[i] = c++; else ar[i] = cc++;
    }
    p.resize(cc);
    for (int i = 0; i < cc; i++) p[i].resize(n, 0);
    
    
    vector<vector<double> > q(n, vector<double>(n));
    vector<double> pp(n);
    for (int i = 0; i < n; i++){
        if (tr[i] == 0){
            for (int j = 0; j < n; j++) q[i][j] = 0;
            for (int j = 0; j < n; j++){
                q[i][j] += 1.0 * a[i][j]/d[i];
            }
            for (int j = 0; j < i; j++){
                if (tr[j] == 0){
                    for (int ij = 0; ij < n; ij++){
                        q[i][ij] += q[i][j] * q[j][ij];
                    }
                    q[i][j] = 0;
                }
            }
            for (int j = 0; j < n; j++){
                if (tr[j] || j > i)
                q[i][j] /= (1 - q[i][i]);
            }
            q[i][i] = 0;
        }
    }   
    
    for (int _ = 0; _ < cc; _++){
        for (int i = 0; i < n; i++){
            if (tr[i] && ar[i] == _) pp[i] = 1; else
            pp[i] = 0;
        }
        for (int i = n - 1; i >= 0; i--){
            if (tr[i] == 0){
                pp[i] = 0;
                for (int j = 0; j < n; j++) pp[i] += q[i][j] * pp[j];
            }
        }
        for (int i = 0; i < n; i++) p[_][i] = pp[i];
    }
    
    vector<vector<double> > P(cc + 1, vector<double>(cc, 0));
    for (int i = 0; i < cc; i++){
        int ij = 0;
        while (tr[ij] == 0 || ar[ij] != i) ij++;
        for (int j = 0; j < cc; j++){
            for (int ii = 0; ii < n; ii++){
                P[i][j] += a[ij][ii] * p[j][ii] / d[ij];
            }
        }
    }
    for (int i = 0; i < cc; i++){
        P[cc][i] = p[i][0];
    }
    
    k--;
    vector<vector<vector<double> > > A(30, vector<vector<double> >(cc, vector<double>(cc)));
    for (int i = 0; i < cc; i++){
        for (int j = 0; j < cc; j++){
            A[0][i][j] = P[i][j];
        }
    }
    for (int _ = 1; _ < 30; _++){
        for (int i = 0; i < cc; i++){
            for (int j = 0; j < cc; j++){
                A[_][i][j] = 0;
                for (int ij = 0; ij < cc; ij++){
                    A[_][i][j] += A[_-1][i][ij] * A[_-1][ij][j];
                }
            }
        }
    }
    vector<vector<double> > B(cc, vector<double>(cc, 0)), C(cc, vector<double>(cc, 0));
    for (int i = 0; i < cc; i++) B[i][i] = 1;

/*
    for (int i =0 ; i < n; i++){
        for (int j = 0; j < n; j++){
            cerr << q[i][j] << " ";
        }
        cerr << "\n";
    }
    cerr << "\n";
*/

    int cccc = 0;
    k--;
    while (k > 0){
        if (k % 2 == 1){
            for (int i = 0; i < cc; i++){
                for (int j = 0; j < cc; j++){
                    C[i][j] = 0;
                    for (int ij = 0; ij < cc; ij++){
                        C[i][j] += B[i][ij] * A[cccc][ij][j];
                    }
                }
            }
            swap(B, C);
        }
        cccc++;
        k /= 2;
    }
    double res = 0;
    for (int i = 0; i < cc; i++) res += B[i][cc - 1] * P[cc][i];
    cout << res << "\n";
    
    return 0;
}