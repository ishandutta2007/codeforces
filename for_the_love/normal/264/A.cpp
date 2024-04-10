#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char s[1000005];
int l[1000005], r[1000005], i, n, p;
int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    r[0] = 1; l[1] = 0; l[n + 1] = 1; r[1] = n + 1;
    for (i = 2; i <= n; i++){
        if (s[i - 1] == 'l'){
            r[i] = i - 1;
            l[i] = l[i - 1];
            r[l[i]] = i;
            l[i - 1] = i;
        }else{
            l[i] = i - 1;
            r[i] = r[i - 1];
            l[r[i]] = i;
            r[i - 1] = i;
        }
    }
    p = r[0];
    while (p != n + 1){
        printf("%d\n", p);
        p = r[p];
    }
}