#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
using namespace std;

typedef long long ll;

int main() {
    int N; cin >> N;

    vector <int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        a[i] -= i;
    }
    reverse(a.begin(), a.end());

    priority_queue<ll> s;
    ll y = 0;

    for(int i = 0; i < N; i++) {
        ll v = a[i];

        y += v;

        s.push(-v);
        s.push(-v);

        y += s.top();
        s.pop();

    }

    cout << y << '\n';
    return 0;
}