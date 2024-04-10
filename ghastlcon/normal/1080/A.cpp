#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;

signed main(void)
{
    int n, k;

    cin >> n >> k;
    cout << (n * 2) / k + (!!((n * 2) % k)) + (n * 5) / k + (!!((n * 5) % k)) + (n * 8) / k + (!!((n * 8) % k)) << endl;

    return 0;
}