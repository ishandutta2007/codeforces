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
char p[999][999];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            p[i][j] = '*';
    for (int i = 0; i < n; ++i) {
        int cnt = i*2 + 1;
        if (cnt > n) cnt = 2*n - cnt;
        for (int j = (n-cnt)/2; j < (n+cnt)/2; ++j)
            p[i][j] = 'D';
    }
    for (int i = 0; i < n; ++i)
        cout << p[i] << endl;

    return 0;
}