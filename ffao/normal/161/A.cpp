#include <stdio.h>
#include <algorithm>
#include <cstring>

int N;
using namespace std;

int soldier[100000];
int vest[100000];

int pf[100000];
int ps[100000];
int tam;

int n, m, x, y;

int main() {
    scanf("%d %d %d %d", &n, &m, &x, &y);
    
    for (int i = 0; i < n; i++) scanf("%d", &soldier[i]);
    for (int i = 0; i < m; i++) scanf("%d", &vest[i]);
    
    int v = 0;
    for (int i = 0; i < n; i++) {
        while (v != m && vest[v] < soldier[i]-x) v++;
        if (v == m) break;
        
        if (vest[v] <= soldier[i]+y) {
            pf[tam]=i+1;
            ps[tam++]=++v;
        }
    }
    
    printf("%d\n",tam);
    for (int i = 0; i < tam; i++) {
        printf("%d %d\n",pf[i], ps[i]);
    }
}