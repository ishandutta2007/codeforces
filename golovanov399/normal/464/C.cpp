#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define float long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

const int base = 1000000007;

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);

    string s;
    vector<pair<LL, LL> > d(10);
    for (itn i = 0; i < 10; i++) d[i] = mp(i, 10);
    cin >> s;
    int n;
    cin >> n;
    vector<string> q(n);
    for (int i = 0; i < n; i++) cin >> q[i];
    for (int i = n - 1; i >= 0; i--){
        int c = q[i][0] - '0';
        q[i].erase(0, 3);
        LL qw = 0, wq = 1;
        for (int j = q[i].length() - 1; j >= 0; j--){
            qw = (qw + wq * (d[q[i][j] - '0'].first)) % base;
            wq = (wq * d[q[i][j] - '0'].second) % base;
        }
        d[c] = mp(qw, wq);
    }
    LL qw = 0, wq = 1;
    for (int j = s.length() - 1; j >= 0; j--){
        qw = (qw + wq * (d[s[j] - '0'].first)) % base;
        wq = (wq * d[s[j] - '0'].second) % base;
    }
    cout << qw << "\n";
    
    return 0;
}