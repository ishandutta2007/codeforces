#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;



int a[N], n, m;
LL S[N], T;
vector <LL> v[N];

LL Calc(int x){
    LL ret = T - S[x];

    sort(v[x].begin(), v[x].end());

    LL sum = 0, tot = 0, mn = 1e18;
    for (int i = 0; i < v[x].size(); i++) tot += v[x][i];
    for (int i = 0; i < v[x].size(); i++){
        mn = min(mn, v[x][i] * i - sum + tot - (v[x].size() - i) * v[x][i]);
        sum += v[x][i];
        tot -= v[x][i];
    }

    return mn + ret;
}

int main(){
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        //a[i] = rand() % 100000;
    }
    for (int i = 1; i < n; i++) T += abs(a[i] - a[i + 1]);
    for (int i = 1; i < n; i++){
        S[a[i]] += abs(a[i] - a[i + 1]);
        S[a[i + 1]] += abs(a[i] - a[i + 1]);
        if (a[i] != a[i + 1]){
            v[a[i]].PB(a[i + 1]);
            v[a[i + 1]].PB(a[i]);
        }
    }


    LL ans = T;
    for (int i = 1; i <= m; i++)
    if (v[i].size()) ans = min(ans, Calc(i));
    cout << ans << endl;
}