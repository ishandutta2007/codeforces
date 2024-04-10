#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    int k;
    cin >> n >> k;
    vector <ll> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    ll best = 1e18;
    int ind = -1;
    for (int i = 0; i < k; ++i) {
        if (n % a[i] < best) {
            best = n % a[i];
            ind = i;
        }
    }
    cout << ind + 1 << " " << n / a[ind] << endl;
}