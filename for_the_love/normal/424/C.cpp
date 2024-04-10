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
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const DB eps = 1e-6;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


int s[N];


int main(){
    int n, p;
    for (int i = 1; i <= 1000000; i++) s[i] = s[i - 1] ^ i;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &p);
        if ((n / i) & 1) p ^= s[i - 1];
        p ^= s[n % i];
        ans ^= p;
    }
    printf("%d\n", ans);

}