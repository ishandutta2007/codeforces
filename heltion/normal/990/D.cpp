#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 1200
char s[MAXN][MAXN];
int main(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if(a != 1 && b != 1) return printf("NO"), 0;
    if(2 <= n && n <= 3 && a == 1 && b == 1) return printf("NO"), 0;
    for(int i = 0; i < n; i += 1)
        for(int j = 0; j < n; j += 1){
            if(i == j) s[i][j] = '0';
            else {
                if(a == 1){
                    if(i + 1 == j && i < n - b || j + 1 == i && j < n - b) s[i][j] = '0';
                    else s[i][j] = '1';
                }
                else{
                    if(i + 1 == j && i < n - a || j + 1 == i && j < n - a) s[i][j] = '1';
                    else s[i][j] = '0';
                }
                    
            }
        }
    printf("YES\n");
    for(int i = 0; i < n; i += 1) printf("%s\n", s[i]);
}