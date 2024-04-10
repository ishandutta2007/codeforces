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
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

string t[N], s[N];

int main(){
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        cin >> s[i] >> t[i];
        if (s[i] > t[i]) swap(s[i], t[i]);
    }
    string now = "";
    int flag = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        if (s[x] > now) now = s[x];
        else if (t[x] > now) now = t[x];
        else flag = 1;
    }
    if (flag) puts("NO"); else puts("YES");
}