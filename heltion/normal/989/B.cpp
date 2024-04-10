#include<cstdio>
#include<algorithm>
#define MAXN 2400
char s[MAXN];
int main(){
    int n, p, ans = 0;
    scanf("%d %d", &n, &p);
    scanf("%s", &s);
    for(int i = 0; i < n; i += 1)
        if(i + p < n){
            if(s[i] == '.' || s[i + p] == '.'){
                if(s[i] == '.' && s[i + p] == '.') s[i] = '0', s[i + p] = '1';
                else if(s[i] == '.') s[i] = 1 - (s[i + p] - '0') + '0';
                else s[i + p] = 1 - (s[i] - '0') + '0';
                ans = 1;
            }
            else if(s[i] != s[i + p]) ans = 1;
        }
        else if(s[i] == '.') s[i] = '0';
        
    if(ans) printf("%s", s);
    else printf("NO");
}