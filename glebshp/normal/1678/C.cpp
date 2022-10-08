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

const int maxn = 5100;

int tnum, n;
int p[maxn];
int good[maxn];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;
    
    for (int tc = 0; tc < tnum; tc++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                good[i] += (p[j] < p[i]);
            }
        }

        long long ans = 0ll;
        for (int i = 0; i < n; i++) {
            long long sum = 0ll;
            for (int j = i - 1; j >= 0; j--) {
                if (p[j] > p[i]) {
                    good[j]--;
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                if (p[j] < p[i]) {
                    ans += sum;
                }
                sum += good[j];
            }
        }

        cout << ans << endl;
    }

    return 0;
}