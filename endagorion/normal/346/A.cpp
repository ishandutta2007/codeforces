#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

long long GCD(long long A, long long B) {
    return B == 0 ? A : GCD(B, A % B);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    long long N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    long long D = a[0];
    for (int i = 1; i < N; ++i) {
        D = GCD(D, a[i]);
    }
    long long Q = a.back() / D;
    cout << ((Q - N) % 2 == 0 ? "Bob\n" : "Alice\n");

	return 0;
}