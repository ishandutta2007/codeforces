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
    if (k + k > n - 1) cout << -1 << "\n"; else {
        cout << k * n << "\n";
        for (itn i = 0; i < n; i++){
            for (int j = 0; j < k; j++){
                cout << i + 1 << " " << (i + j + 1) % n + 1 << "\n";
            }
        }
    }
    
    return 0; 
}