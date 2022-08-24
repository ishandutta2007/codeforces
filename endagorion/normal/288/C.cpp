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


int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    int NN = N;
    vector<int> a(N + 1);
    while (N > 0) {
        int K = 1;
        while (2 * K <= N) {
            K *= 2;
        }
        for (int i = 0; i + K <= N; ++i) {
            a[i + K] = K - i - 1;
            a[K - i - 1] = i + K;
        }
        N = 2 * K - N - 2;
    }
    long long sum = 0;
    for (int i = 0; i <= NN; ++i) {
        sum += i ^ a[i];
    }
    cout << sum << '\n';
    for (int i = 0; i <= NN; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

	return 0;
}