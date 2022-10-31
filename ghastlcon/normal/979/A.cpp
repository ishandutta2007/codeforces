#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void) //pie.cpp
{
    long long n;

    // freopen("pie.in" , "r", stdin );
    // freopen("pie.out", "w", stdout);

    cin >> n;
    cout << (!n ? 0 : n & 1 ? (n + 1) >> 1 : n + 1) << endl;

    return 0;
}