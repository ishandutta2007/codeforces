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

//int a[3000];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    int sum = 0, zeros = 0;
    for (int i = 0; i < 2 * N; ++i) {
        double x;
        cin >> x;
        int y = (int)(1000 * x + 0.5) % 1000;
        sum += y;
        if (y == 0) {
            ++zeros;
        }
    }
    sum -= N * 1000;
    ///sum = abs(sum);
    while (zeros > 0 && sum < -500) {
        --zeros;
        sum += 1000;
        //sum = abs(sum);
    }
    sum = abs(sum);
    printf("%.3lf\n", 0.001 * sum);

	return 0;
}