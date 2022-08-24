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
    int N, K;
    cin >> N >> K;
    if (K > N) {
        cout << -1 << '\n';
        return 0;
    }
    if (K == 1 && N > 1) {
        cout << -1 << '\n';
        return 0;
    }
    string s(N, 'a');
    for (int i = 1; i < N; i += 2) {
        s[i] = 'b';
    }
    for (int j = 0; j < K - 2; ++j) {
        s[N - j - 1] = 'a' + K - 1 - j;
    }
    cout << s << '\n';

	return 0;
}