#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)


const int N = 3e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-6;

int a[N], ans[N], b[N];

bool cmp(int i, int j){return a[i] < a[j];}


int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        b[i] = i;
    }
    sort(b + 1, b + n + 1, cmp);

    int l = 0;
    for (int i = 1; i <= n; i++){
        if (l >= a[b[i]]){
            l++;
            ans[b[i]] = l;
        }else{
            l = a[b[i]];
            ans[b[i]] = l;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}