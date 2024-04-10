#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<LL, LL> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

LL a, b, n;


int main(){
    cin >> n >> a >> b;
    n *= 6;
    if (a * b >= n){
        cout << a * b << endl;
        cout << a << " " << b << endl;
        return 0;
    }
    LL mn = 1e18;
    PI p;
    for (LL i = a; i <= sqrt(n) + 100; i++)
    if (b <= (n - 1) / i + 1 && i * ((n - 1) / i + 1) - n < mn){
        p.first = i, p.second = ((n - 1) / i + 1);
        mn = i * ((n - 1) / i + 1) - n;
    }
    for (LL i = b; i <= sqrt(n) + 100; i++)
    if (a <= (n - 1) / i + 1 && i * ((n - 1) / i + 1) - n < mn){
        p.second = i, p.first = ((n - 1) / i + 1);
        mn = i * ((n - 1) / i + 1) - n;
    }
    cout << mn + n << endl;
    cout << p.first << " " << p.second << endl;
}