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
    
    vector<vector<int> > p(2001);
    for (int i = 1; i < 2001; i++){
        for (int j = 1; j < 2001; j++){
            if (i % j == 0) p[i].pb(j);
        }
    }
    int n, k;
    cin >> n >> k;
    vector<vector<int> > a(n + 1, vector<int>(k));
    for (int i = 1; i <= n; i++) a[i][0] = 1;
    for (int j = 1; j < k; j++){
        for (int i = 1; i <= n; i++){
            for (int ij = 0; ij < p[i].size(); ij++){
                a[i][j] = (a[i][j] + a[p[i][ij]][j - 1]) % 1000000007;
            }
        }
    }
    int s = 0;
    for (int i = 1; i <= n; i++) s = (s + a[i][k - 1]) % 1000000007;
    cout << s << "\n";
    
    return 0; 
}