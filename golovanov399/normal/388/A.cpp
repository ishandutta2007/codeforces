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
    vector<int> a(n, 0), x(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++){
        int j = 0;
        while (x[i] < a[j]) j++;
        a[j]++;
    }
    int i = 0;
    while (i < n && a[i] > 0) i++;
    cout << i;
    
    return 0; 
}