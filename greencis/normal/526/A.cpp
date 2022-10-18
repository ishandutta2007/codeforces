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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
char s[10005];

int main()
{
    for (int i = 0; i < 10005; ++i) s[i] = 0;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int good = 1;
            for (int k = 0; k < 5; ++k) {
                if (s[i + j * k] != '*') good = 0;
            }
            if (good) { printf("yes"); return 0; }
        }
    }
    printf("no");

    return 0;
}