#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

vector <int> t;

void print(int a, int b, int c, int d) {
    cout << a << ' ' << c << ' ';
    for (int i = 0; i < t.size(); ++i) {
        cout << t[i] << ' ';
    }
    cout << d << ' ' << b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    int a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;
    if (n == 4) {
        cout << "-1\n";
        return 0;
    }
    if (k <= n) {
        cout << "-1\n";
        return 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (i != a && i != b && i != c && i != d) t.push_back(i);
    }
    print(a, b, c, d);
    print(c, d, a, b);
}