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

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

char s[105][105];
int a[105][105];

int main(){
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
    if (s[i][j] == 'B'){
        if (a[i][j] != 1){
            ans++;
            int d = 1 - a[i][j];
            for (int x = i; x >= 0; x--)
            for (int y = j; y >= 0; y--)
                a[x][y] += d;
        }
    }else{
        if (a[i][j] != -1){
            ans++;
            int d = -1 - a[i][j];
            for (int x = i; x >= 0; x--)
            for (int y = j; y >= 0; y--)
                a[x][y] += d;
        }
    }
    printf("%d\n", ans);
}