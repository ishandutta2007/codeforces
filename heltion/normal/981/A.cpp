#include<bits/stdc++.h>
bool test(char *s, int k){
    if(k == 0) return true;
    for(int i = 0; i < k - 1 - i; i += 1)
        if(s[i] != s[k - 1 - i]) return true;
    return false;
}
int main(){
    char s[100];
    scanf("%s", s);
    int n = strlen(s);
    for(int i = n; i >= 0; i -= 1)
        for(int j = 0; j + i <= n; j += 1)
            if(test(s + j, i)){
                printf("%d\n", i);
                return 0;
            }
}