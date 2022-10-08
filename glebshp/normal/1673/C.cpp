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

const int mdl = 1000 * 1000 * 1000 + 7;
const int maxn = 40 * 1000 + 10;
const int mpals = 510;

int ans[mpals][maxn];
vector <int> pals;

bool isPalindromic(int n) {
    vector <int> digits;
    while (n > 0) {
        digits.pb(n % 10);
        n /= 10;
    }

    int len = (int) digits.size();
    for (int i = 0; i < len / 2; i++) {
        if (digits[i] != digits[len - 1 - i]) {
            return false;
        }
    }

    return true;
}

void precalc() {
    for (int i = 1; i < maxn; i++) {
        if (isPalindromic(i)) {
            pals.pb(i);
        }
    }    

    ans[0][0] = 1;
    for (int i = 0; i < (int) pals.size(); i++) {
        for (int j = 0; j < maxn; j++) {
            ans[i + 1][j] = ans[i][j];
            if (j >= pals[i]) {
                ans[i + 1][j] += ans[i + 1][j - pals[i]];
                if (ans[i + 1][j] >= mdl) {
                    ans[i + 1][j] -= mdl;
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    precalc();

    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++) {
        int n;
        cin >> n;
        cout << ans[pals.size()][n] << endl;
    }

    return 0;
}