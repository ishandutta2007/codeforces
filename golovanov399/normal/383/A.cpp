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

using namespace std; 

int main(){ 
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k = 0;
    for (int i = 0; i < n; i++) if (a[i] == 0) k++;
    LL ans = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 0) k--; else
        ans += k;
    }
    cout << ans;
    
    return 0; 
}