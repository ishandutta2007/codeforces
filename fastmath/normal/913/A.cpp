#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <random>
#include <time.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
#define int long long

signed main(){  
    int n, m;
    cin >> n >> m;
    if (30 < n){
        cout << m << '\n';
    }
    else{
        cout << m % (1 << n) << '\n';
    }

    return 0;
}