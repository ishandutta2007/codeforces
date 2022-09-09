#include<cstdio>
#include<algorithm>
#define MAXN 120
char s[MAXN];
int main(){
    scanf("%s", s);
    for(int i = 1; s[i]; i += 1)
        if(s[i - 1] + s[i] + s[i + 1] == 'A' + 'B' +'C')
            if(s[i - 1] * s[i] * s[i + 1] == 'A' * 'B' * 'C')
                return printf("YES"), 0;
    return printf("NO"), 0;
}