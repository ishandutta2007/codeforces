#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int n,a[10005];

int main()
{
    cin >> n;
    for (int i = 0; i < n;++i)
        cin >> a[i];
    sort(a,a+n);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";

    return 0;
}