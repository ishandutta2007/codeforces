#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

const int MAXNM = 1000000;

char s[1 + MAXNM + 1];
int add[1 + MAXNM];
bool col[1 + MAXNM];

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m >> (s + 1);
        int ans = 0;
        for (int i = 1, c = 0, j = 0; i <= n * m; i++, c = (c + 1) % m) {
            if (s[i] == '1') {
                if (!col[c]) {
                    ans++;
                    col[c] = true;
                }
                if (j == 0) {
                    ans++;
                } else {
                    if (i - j >= m) {
                        ans++;
                    } else {
                        ans++;
                        add[c]--;
                        add[(c + (m - (i - j))) % m]++;
                    }
                }
                j = i;
            }
            ans += add[c];
            cout << ans << " ";
        }
        cout << "\n";


        for (int i = 0; i <= n * m; i++) {
            add[i] = 0;
            col[i] = false;
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}