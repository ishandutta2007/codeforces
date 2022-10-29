#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long f(long long n, long long m){
    return m ? f(m, n%m) + n/m : n-1;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    long long n, m;
    cin >> n >> m;
    cout << f(n, m) << endl;
}