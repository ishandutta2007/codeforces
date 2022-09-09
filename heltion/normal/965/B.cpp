#include<cstdio>
#define MAXN 120
char s[MAXN][MAXN];
int a[MAXN][MAXN];
int main(){
    int n, k, max = -1, ansx, ansy;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i += 1) scanf("%s", s[i]);
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < n; j += 1){
            if(j + k <= n){
                bool flag = true;
                for(int p = 0; p < k; p += 1)
                    if(s[i][j + p] != '.') flag = false, p = k;
                if(flag) for(int p = 0; p < k; p += 1) a[i][j + p] += 1;
            }
            if(i + k <= n){
                bool flag = true;
                for(int p = 0; p < k; p += 1)
                    if(s[i + p][j] != '.') flag = false, p = k;
                if(flag) for(int p = 0; p < k; p += 1) a[i + p][j] += 1;
            }
        }
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < n; j += 1)
            if(a[i][j] > max)
                ansx = i + 1, ansy = j + 1, max = a[i][j];
    printf("%d %d", ansx, ansy);
}