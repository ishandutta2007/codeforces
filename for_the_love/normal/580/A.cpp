#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
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
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
int a[N];

int main(){
    int n;
    scanf("%d", &n);
    int last = -1, cnt = 0, ans = 1;
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if (a[i] >= last){
            cnt++;
            last = a[i];
        }else{
            cnt = 1;
            last = a[i];
        }
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);

}