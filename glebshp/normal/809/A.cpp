#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int size = 1000 * 1000;
const long long mdl = 1000 * 1000 * 1000 + 7;

int n;
int x[size];
long long pwr[size];

int main () {
//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    pwr[0] = 1ll;
    for (int i = 1; i < size; i++) {
    	pwr[i] = (pwr[i - 1] * 2) % mdl;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &x[i]);
    }

    sort(x, x + n);
    
    long long ans = 0ll;

    for (int i = 0; i < n; i++) {
    	ans = (ans + mdl - (x[i] * 1ll * pwr[n - i - 1]) % mdl) % mdl;
    	ans = (ans + x[i] * 1ll * pwr[i]) % mdl;
    }

    cout << ans << endl;

    return 0;
}