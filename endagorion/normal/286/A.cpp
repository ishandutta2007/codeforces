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
    if (N % 4 == 2 || N % 4 == 3) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> ans(N);
    ans[N / 2] = N / 2;
    for (int i = 0; i < N / 2; i += 2) {
        ans[i] = i + 1;
        ans[i + 1] = N - i - 1;
        ans[N - i - 1] = N - i - 2;
        ans[N - i - 2] = i;
    }
    if (N % 4 == 1) {
        ans[N / 2] = N / 2;
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';

	return 0;
}