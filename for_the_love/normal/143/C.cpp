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
    long long n;
    cin >> n;
    long long ans = 1e15;
    for (long long i = 1; i * i <= n; i++)
    if (n % i == 0){
        long long t = n / i;
        for (long long j = 1; j * j <= t; j++)
        if (t % j == 0) ans = min(ans, (i + 1) * (j + 2) * (t / j + 2) - n);
        t = i;
        for (long long j = 1; j * j <= t; j++)
        if (t % j == 0) ans = min(ans, (n / i + 1) * (j + 2) * (t / j + 2) - n);
    }
    cout << ans << " " << n * 8 + 9 << endl;
}