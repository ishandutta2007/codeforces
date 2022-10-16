#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <functional>

using namespace std;

#define INF 1000000000

int n,k;
int arr[30000];

struct call {
    int t;
    int d;
};

call c[10000];
int pd[4001][4001];

int main() {
    scanf("%d %d",&n, &k);
    
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        int t, d;
        scanf("%d %d", &t, &d);
        c[cnt].t=t;
        c[cnt++].d=d;
    }
    
    c[cnt++].t = 86401;
    for (int j = 0; j<=k; j++) pd[j][0]=1;
    
    for (int j = 0; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            pd[j][i] = max(pd[j][i-1],c[i].t)+c[i].d;
            if (j > 0) pd[j][i] = min(pd[j][i],pd[j-1][i-1]);
        }
    }
    
    int best = 0;
    for (int i = 0; i <= n; i++) {
        int t = pd[k][i];
        int d = c[i+1].t-t;
        best = max(d,best);
    }
    
    printf("%d\n",best);
}