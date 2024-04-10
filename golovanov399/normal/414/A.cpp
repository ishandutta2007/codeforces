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
    
    int n, k;
    cin >> n >> k;
    if (n / 2 > k){
        cout << "-1\n";
        return 0;
    }
    if (n == 1){
        if (k == 0) cout << 1; else cout << -1;
        return 0;
    }
    cout << (k - n / 2 + 1) << " " << (k - n / 2 + 1) * 2 << " ";
    for (int i = 3; i < n; i += 2){
        cout << (k - n / 2 + 1) * 2 + i << " " << (k - n / 2 + 1) * 2 + i + 1 << " ";
    }
    if (n % 2 == 1) cout << 999999999;
    
    return 0; 
}