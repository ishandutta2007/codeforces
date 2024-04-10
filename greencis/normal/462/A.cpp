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

int n;
char p[1005][1005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> (p[i+1]+1);
    }
    bool good = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int qqq = 0;
            if (p[i-1][j] == 'o') ++qqq;
            if (p[i+1][j] == 'o') ++qqq;
            if (p[i][j-1] == 'o') ++qqq;
            if (p[i][j+1] == 'o') ++qqq;
            if (qqq % 2 != 0) good = false;
        }
    }
    if (good) cout << "YES"; else cout << "NO";

    return 0;
}