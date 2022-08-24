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
    if (N % 2 == 0) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        cout << i << ' ';
    }
    cout << '\n';

    for (int i = 0; i < N; ++i) {
        cout << i << ' ';
    }
    cout << '\n';

    for (int i = 0; i < N; ++i) {
        cout << (2 * i) % N << ' ';
    }
    cout << '\n';


	return 0;
}