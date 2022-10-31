#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <string>
#include <cstring>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9+100;
const ll lINF = 1e18;
const double E = 2.718281828459045;

int m, s;
vector<int> ans;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> m >> s;
    int s2 = s;
    if (s== 0 && m==1) {
        cout << "0 0" << endl;
        return 0;
    }
    if (s==0) {
        cout << "-1 -1" << endl;
        return 0;
    } else if (s == 1) {
        cout << 1;
        for (int i = 0; i < m-1; i++) cout << "0";
        cout << " ";
        cout << 1;
        for (int i = 0; i < m-1; i++) cout << "0";
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int digit = 0;
        if (i == 0) digit = 1, s--;
        while (s > 9*(m-i-1)) digit++, s--;
        if (digit <= 9) ans.pb(digit);
        else {
            cout << "-1 -1" << endl;
            return 0;
        }
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << " ";
    for (int i = 0; i < m; i++) {
        cout << min(9, s2);
        s2-= min(9, s2);
    }
    return 0;
}