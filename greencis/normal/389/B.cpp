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
#include <map>
#include <queue>
#include <utility>
#include <iomanip>
using namespace std;

int n;
char a[105][105];

int main()
{
    cin>>n;
    for (int i = 0; i <n; ++i)
        cin>>a[i];

    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < n-1; ++j) {
            if (a[i][j] == '#' && a[i][j-1] == '#' && a[i][j+1] == '#' && a[i-1][j] == '#' && a[i+1][j] == '#') {
                a[i][j] =a[i][j-1] =a[i][j+1] =a[i-1][j] =a[i+1][j] = '.';
            }
        }
    }

    bool good = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n;++j)
    if (a[i][j] == '#') {
        good = false;
        break;
    }

    cout << (good?"YES":"NO");

    return 0;
}