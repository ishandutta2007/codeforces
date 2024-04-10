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

bool issqr(int x){
    for (int i = 0; i * i <= x; i++){
        if (i * i == x) return true;
    }
    return false;
}

int main(){ 
    
    vector<vector<int> > v(101);
    int p[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    v[1].pb(1);
    v[2].pb(3);
    v[2].pb(4);
    for (int i = 1; i < 25; i++){
        bool flag = false;
        for (int x = 0; x <= p[i] && !flag; x++){
            for (int y = 0; x + y <= p[i] && !flag; y++){
                if (issqr(x + 4 * y + 9 * (p[i] - x - y))){
                    flag = true;
                    for (int j = 0; j < x; j++) v[p[i]].pb(1);
                    for (int j = 0; j < y; j++) v[p[i]].pb(2);
                    for (int j = 0; j < p[i] - x - y; j++) v[p[i]].pb(3);
                }
            }
        }
        if (!flag) cout << "FAIL " << p[i] << "\n";
    }
    for (int i = 1; i <= 100; i++){
        if (v[i].size() == 0){
            int j = 2;
            while (i % j != 0) j++;
            for (int ij = 0; ij < i; ij++){
                v[i].pb(v[j][ij % j] * v[i / j][ij / j]);
            }
        }
    }
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << v[n][i] * v[m][j] << " ";
        }
        cout << "\n";
    }
    
    return 0; 
}