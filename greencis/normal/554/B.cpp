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
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,ans;
char s[105][105],ss[105][105];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '1') v.push_back(j);
            strcpy(ss[j],s[j]);
        }
        for (int j = 0; j < v.size(); ++j) {
            for (int k = 0; k < n; ++k)
                ss[k][v[j]] = 97 - ss[k][v[j]];
        }
        int curans = 0;
        for (int j = 0; j < n; ++j) {
            bool good = true;
            for (int k = 0; k < n; ++k) {
                if (ss[j][k] == '1') { good = false; break; }
            }
            if (good) ++curans;
        }
        ans = max(ans, curans);
    }
    cout << ans;

    return 0;
}