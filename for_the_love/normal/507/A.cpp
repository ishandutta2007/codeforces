#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
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
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, a[N], b[N];

bool cmp(int i, int j){return a[i] < a[j];}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[i] = i;
    }
    sort(b, b + n, cmp);
    vector <int> ans;
    for (int i = 0; i < n; i++){
        if (a[b[i]] <= m){
            m -= a[b[i]];
            ans.PB(b[i] + 1);
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}