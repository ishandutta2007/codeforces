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

int n,k;
string s;

int main()
{
    cin >> n >> k >> s;
    if (k <= (n+1)/2) {
        for (int i = 0; i < k - 1; ++i)
            printf("LEFT\n");
        for (int i = 0; i < n; ++i) {
            printf("PRINT %c\n",s[i]);
            if (i < n-1) printf("RIGHT\n");
        }
    } else {
        for (int i = 0; i < n - k; ++i)
            printf("RIGHT\n");
        for (int i = n-1; i >= 0; --i) {
            printf("PRINT %c\n",s[i]);
            if (i > 0) printf("LEFT\n");
        }
    }

    return 0;
}