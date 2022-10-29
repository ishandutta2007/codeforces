#include <bits/stdc++.h>
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


int mx[N], a[N];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = n; i >= 1; i--){
        if (i == n) mx[i] = a[i];
        else mx[i] = max(a[i], mx[i + 1]);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", max(mx[i + 1] - a[i] + 1, 0));
}