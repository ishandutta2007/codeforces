#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    long long n, t;
    cin >> n;
    t = 1;
    while (n % t == 0) t *= 3;
    cout << n / t + 1 << endl;
}