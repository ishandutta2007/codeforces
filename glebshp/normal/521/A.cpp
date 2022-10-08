#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;
const int mdl = 1000 * 1000 * 1000 + 7;

int cnt[256];
int n;
char buf[size];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    scanf("%s", buf);
    for (int i = 0; i < n; i++)
    	cnt[buf[i]]++;

    int mx = max(max(cnt['A'], cnt['C']), max(cnt['G'], cnt['T']));
    long long d = 0;
    d += (cnt['A'] == mx);
    d += (cnt['C'] == mx);
    d += (cnt['G'] == mx);
    d += (cnt['T'] == mx);

    long long ans = 1;
    for (int i = 0; i < n; i++) {
    	ans = (ans * 1ll * d) % mdl;
    }

    cout << ans << endl;

    return 0;
}