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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    long long s = 0;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        s += min(v[x], v[y]);
    }
    cout << s << "\n";
    
    return 0; 
}