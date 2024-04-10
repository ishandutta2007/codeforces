#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int n,a[999999],cnt,mn=2e9,mni,mnc;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
        if (mn>a[i]) {mn = a[i];mni = i;mnc=1;}
        else if(mn==a[i]) {mn = a[i];mni = i;++mnc;}
    }

    int curidx = 0;
    while (curidx < n && a[curidx] == mn) --mnc, ++curidx;

    for (int i = 0;  i< n-1; ++i)
        if (a[i] > a[i+1]) ++cnt;
    if (a[n-1] > a[0]) ++cnt;

    if (cnt > 1) {
        cout << -1;
    } else {
        if (mnc > 0) {
            int j = n-1;
            for (; j >= 0 && mnc > 0; --j)
                if (a[j] == mn) --mnc;
            cout << n-j-1;
        } else cout << 0;
    }

    return 0;
}