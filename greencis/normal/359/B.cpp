#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int res[2*n];
    for (int i = 0; i < 2*n;++i)
    {
        res[i] = 2*n-i;
    }

    int curIdxPair = 0;
    while (k--) {
        int t = res[curIdxPair];
        res[curIdxPair] = res[curIdxPair+1];
        res[curIdxPair+1] = t;
        curIdxPair+=2;
    }

    for (int i = 0; i < 2*n;++i)
    {
        cout << res[i]<<" ";
    }

    return 0;
}