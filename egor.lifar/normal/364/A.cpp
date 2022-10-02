#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <map>
#include<string.h>s

using namespace std;


int a;
int n;
string s;
long long d[4000][4000];
map<int, long long> m;



int main() {
    cin >> a >> s;
    n = s.size();
    long long k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            d[i][j] = s[j] - '0' + (j > i ? d[i][j - 1]: 0);
            m[d[i][j]]++;
            k++;
        }
    }
    if (a == 0) {
        cout << m[0] * k + k * m[0] - m[0] * m[0] << endl;
        return 0;
    }
    long long ans = 0;
    for (int i = 1; i <= 9 * n; i++) {
        if (a % i == 0) {
            ans += m[i] * m[a / i];
        }
    }
    cout << ans << endl;
    return 0;
}