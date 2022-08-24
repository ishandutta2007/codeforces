#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <algorithm> 
#include <cassert> 
#include <string> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <map> 
#include <set> 

#define itn int 
#define float long double 
#define LL long long 
#define pb push_back 
#define mp make_pair 

using namespace std; 

int main(){ 
    
    int n, m;
    cin >> n >> m;
    vector<vector<LL> > a(n, vector<LL>(m));
    for (itn i = 0; i < n; i++){
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    vector<vector<LL> > lu(n, vector<LL>(m));
    vector<vector<LL> > ld(n, vector<LL>(m));
    vector<vector<LL> > ru(n, vector<LL>(m));
    vector<vector<LL> > rd(n, vector<LL>(m));
    lu[0][0] = a[0][0];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0 && j > 0) lu[i][j] = lu[i][j - 1] + a[i][j]; else
            if (i > 0 && j == 0) lu[i][j] = lu[i - 1][j] + a[i][j]; else
            if (i > 0 && j > 0) lu[i][j] = max(lu[i - 1][j], lu[i][j - 1]) + a[i][j];
        }
    }
    ld[n - 1][0] = a[n - 1][0];
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < m; j++){
            if (i == n - 1 && j > 0) ld[i][j] = ld[i][j - 1] + a[i][j]; else
            if (i < n - 1 && j == 0) ld[i][j] = ld[i + 1][j] + a[i][j]; else
            if (i < n - 1 && j > 0) ld[i][j] = max(ld[i + 1][j], ld[i][j - 1]) + a[i][j];
        }
    }
    ru[0][m - 1] = a[0][m - 1];
    for (int i = 0; i < n; i++){
        for (int j = m - 1; j >= 0; j--){
            if (i == 0 && j < m - 1) ru[i][j] = ru[i][j + 1] + a[i][j]; else
            if (i > 0 && j == m - 1) ru[i][j] = ru[i - 1][j] + a[i][j]; else
            if (i > 0 && j < m - 1) ru[i][j] = max(ru[i - 1][j], ru[i][j + 1]) + a[i][j];
        }
    }
    rd[n - 1][m - 1] = a[n - 1][m - 1];
    for (int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0; j--){
            if (i == n - 1 && j < m - 1) rd[i][j] = rd[i][j + 1] + a[i][j]; else
            if (i < n - 1 && j == m - 1) rd[i][j] = rd[i + 1][j] + a[i][j]; else
            if (i < n - 1 && j < m - 1) rd[i][j] = max(rd[i + 1][j], rd[i][j + 1]) + a[i][j];
        }
    }
    LL ans = 0;
    for (int i = 1; i < n - 1; i++){
        for (int j = 1; j < m - 1; j++){
            if (lu[i - 1][j] + rd[i + 1][j] + ld[i][j - 1] + ru[i][j + 1] > ans) ans = lu[i - 1][j] + rd[i + 1][j] + ld[i][j - 1] + ru[i][j + 1];
            if (lu[i][j - 1] + rd[i][j + 1] + ld[i + 1][j] + ru[i - 1][j] > ans) ans = lu[i][j - 1] + rd[i][j + 1] + ld[i + 1][j] + ru[i - 1][j];
        }
    }
    cout << ans;
    
    return 0; 
}