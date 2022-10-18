#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory.h>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> n;
        if (n&1) cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}