#include<bits/stdc++.h>
#define maxn 2000
char s[maxn][maxn];
int a[maxn];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i += 1){
        scanf("%s", s[i]);
        for(int j = 0; j < m; j += 1) a[j] += s[i][j] == '1';
    }
    for(int i = 0; i < n; i += 1){
        bool flag = true;
        for(int j = 0; j < m; j += 1)
            if(s[i][j] == '1' and a[j] == 1) flag = false;
        if(flag) return printf("Yes"), 0;
    }
    printf("No");
}