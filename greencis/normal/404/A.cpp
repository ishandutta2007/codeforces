#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
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

int n;
char p[999][999];

int main()
{
    cin >> n;
    for (int i = 0 ; i< n; ++i) {
        cin >> p[i];
    }

    char a1 = p[0][0], a2 = p[0][1];
    bool good1 = a1 != a2;
    for (int i = 0; i < n && good1; ++i) {
        if (p[i][i] != a1) {
            good1 = false;
            break;
        }
    }

    for (int i = 0; i < n&& good1; ++i) {
        if (p[n-1-i][i] != a1) {
            good1 = false;
            break;
        }
    }

    for (int i = 0; i < n&& good1; ++i) {
        for (int j = 0;  j < n && good1; ++j) {
            if (i != j && i != n-1-j) {
                if (p[i][j] != a2) {
                    good1 = false;
                    break;
                }
            }
        }
    }

    cout << (good1 ?  "YES" : "NO");

    return 0;
}