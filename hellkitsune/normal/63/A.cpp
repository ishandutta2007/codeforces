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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s[100], t[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> s[i] >> t[i];
    REP(i, n) if (t[i] == "rat") {
        cout << s[i] << '\n';
    }
    REP(i, n) if (t[i] == "woman" || t[i] == "child") {
        cout << s[i] << '\n';
    }
    REP(i, n) if (t[i] == "man") {
        cout << s[i] << '\n';
    }
    REP(i, n) if (t[i] == "captain") {
        cout << s[i] << '\n';
    }
    return 0;
}