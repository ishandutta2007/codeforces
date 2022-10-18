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

int n,res,state[99999], last; /// 1 - fallen
char p[99999];

int main()
{
    cin >> n >> p;
    bool was = false;
    for (int i = 0; i < n; ++i) {
        if (p[i] == 'L') {
            for (int j = last; j <= i; ++j)
                state[j] = 1;
            last = i+1;
        } else if (p[i] == 'R') {
            int idx = i;
            while (idx < n && p[idx] != 'L') ++idx;
            if (idx >= n) {
                for (int j = i; j < n; ++j)
                    state[j] = 1;
                break;
            }
            int cnt = idx - i + 1;
            if (cnt % 2 == 0) {
                for (int j = i; j <= idx; ++j)
                    state[j] = 1;
                last = idx + 1;
            } else {
                for (int j = i; j <= idx; ++j)
                    state[j] = 1;
                last = idx + 1;
                state[(idx+i)/2] = 0;
            }
            i = idx;
        }
    }

    for (int i = 0; i < n; ++i)
        res += state[i];
    cout << n - res;

    return 0;
}