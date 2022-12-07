#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int del = 0;
    for (int i = 1; i < (int)s.length(); ++i) {
        if (s[i] == '/' && s[i] == s[i - del - 1])
            ++del;
        else
            s[i - del] = s[i];
    }
    s.erase((int)s.length() - del);
    while ((int)s.length() > 1 && s[(int)s.length() - 1] == '/')
        s.erase((int)s.length() - 1);
    cout << s << endl;
    return 0;
}