#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iomanip>
using namespace std;

int a[100005],res[100005],busy[100005];

int main()
{
    int n,m;
    cin >> n >> m;

    for (int i =0;i<n;++i) {
        cin>>a[i];
        ++busy[a[i]-1];
    }

    int r = 0;
    for (int i = 0; i < 100000; ++i)
    {
        r += busy[i] != 0;
    }
    res[0] = r;
    for (int i = 1; i < n; ++i) {
        --busy[a[i-1]-1];
        if (busy[a[i-1]-1] == 0)
            --r;
        res[i] = r;
    }

    while (m--) {
        int l;
        cin>>l;
        cout << res[l-1]<<endl;
    }
    return 0;
}