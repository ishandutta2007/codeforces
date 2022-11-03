#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*

*/

void NO() {
    cout << -1 << endl;
    exit(0);
}

//int s[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<li>> a(n, vector<li>(n));
    int i1, j1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) {
                i1 = i;
                j1 = j;
            }
        }
    }

    if(n == 1) {
       cout << 1 << endl;
       return 0;
    }

    li s = 0;
    int i2 = (i1 == 0 ? 1 : 0);
    for(int j = 0; j < n; j++)
        s += a[i2][j];

    li s1 = 0;
    for(int j = 0; j < n; j++) {
        s1 += a[i1][j];
    }

    a[i1][j1] = s - s1;

    if(a[i1][j1] <= 0) {
        NO();
    }

    for(int i = 0; i < n; i++) {
        s1 = 0;
        for(int j = 0; j < n; j++)
            s1 += a[i][j];
        if(s1 != s)
            NO();
    }

    for(int j = 0; j < n; j++) {
        s1 = 0;
        for(int i = 0; i < n; i++)
            s1 += a[i][j];

        if(s1 != s)
            NO();
    }

    s1 = 0;
    for(int i = 0; i < n; i++)
        s1 += a[i][i];

    if(s1 != s)
        NO();

    s1 = 0;
    for(int i = 0; i < n; i++)
        s1 += a[i][n - i - 1];

    if(s1 != s)
        NO();

    cout << a[i1][j1] << endl;
}