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
typedef long long ll;
typedef long double ld;

int n,fact[99],ansi,cnt[99];
char s[100005],ans[100105];

int main()
{
    cin >> n >> s;
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 9; ++i) fact[i] = fact[i-1] * i;
    for (int i = 0; i < n; ++i) {
        int curnum = s[i] - 48;
        curnum = fact[curnum];
        for (int j = 2; j <= 9; ++j) {
            while (curnum % j == 0) cnt[j]++, curnum /= j;
        }
    }
    while (cnt[7] > 0) {
        ans[ansi++] = '7';
        --cnt[7];
        --cnt[2]; --cnt[3];
        --cnt[5];
        --cnt[2]; --cnt[2];
        --cnt[3];
        --cnt[2];
    }

    while (cnt[5] > 0) {
        ans[ansi++] = '5';
        --cnt[5];
        --cnt[2]; --cnt[2];
        --cnt[3];
        --cnt[2];
    }

    while (cnt[3] > 0) {
        ans[ansi++] = '3';
        --cnt[3];
        --cnt[2];
    }

    while (cnt[2] > 0) {
        ans[ansi++] = '2';
        --cnt[2];
    }

    cout << ans;

    return 0;
}