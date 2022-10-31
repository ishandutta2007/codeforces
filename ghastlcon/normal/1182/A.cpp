#include <iostream>
#include <algorithm>
#include <cstdio>
#pragma GCC optimize("O3")
using namespace std;

int main(void)
{
    int n;

    cin >> n;
    cout << (n & 1 ? 0 : (1LL << (n >> 1))) << endl;

    return 0;
}