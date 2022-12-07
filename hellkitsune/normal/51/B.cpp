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

vector<int> ans;
string s, t;
vector<int> st;

int main() {
    while (cin >> t) {
        s += t;
    }
    int n = (int)s.length();
    REP(i, n) if (s[i] == '<') {
        if (s[i + 1] == 't' && s[i + 2] == 'a') {
            st.pb(0);
        } else if (s[i + 1] == 't' && s[i + 2] == 'd') {
            ++st.back();
        } else if (s[i + 1] == '/' && s[i + 2] == 't' && s[i + 3] == 'a') {
            ans.pb(st.back());
            st.pop_back();
        }
    }
    sort(ans.begin(), ans.end());
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}