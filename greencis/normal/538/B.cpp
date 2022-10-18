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
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

string s,ans[9];

int main()
{
    cin >> s;
    int mx = 0;
    for (int i = 0; i < s.size(); ++i) mx = max(mx, s[i] - 48);
    for (int i = 0; i < s.size(); ++i)
        for (int j = 0; j < 9; ++j)
            ans[j] += "0";
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s[i] - 48; ++j) {
            ans[j][i] = '1';
        }
    }
    for (int i = 0; i < 9; ++i) {
        while (ans[i].size() && ans[i][0] == '0')
            ans[i].erase(0, 1);
    }
    cout << mx << endl;
    for (int i = 0; i < mx; ++i)
        cout << ans[i] << " ";

    return 0;
}