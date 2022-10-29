#pragma comment(linker, /STACK:102400000,102400000)
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
#include <unordered_set>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int a[3], b[3];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
        scanf("%d%d", &a[i], &b[i]);
    for (int i = b[0]; i >= a[0]; i--)
    if (n - i >= a[1] + a[2] && n - i <= b[1] + b[2]){
        printf("%d ", i);
        n -= i;
        break;
    }
    for (int i = b[1]; i >= a[1]; i--)
    if (n - i >= a[2] && n - i <= b[2]){
        printf("%d %d\n", i, n - i);
        break;
    }







}