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
#include <bitset>
using namespace std;

int n,m,mn,mx,a[9999];

int main()
{
    cin >> n >> m >> mn >> mx;
    bool maxgood = false, mingood = false;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        if (a[i] == mn) mingood = true;
        else if (a[i] == mx) maxgood = true;
        else if (a[i] > mx || a[i] < mn) {cout << "Incorrect";return 0;}
    }
    if (mingood || maxgood) cout << "Correct";
    else {
        if (n-m > 1) cout << "Correct";
        else cout << "Incorrect";
    }

    return 0;
}