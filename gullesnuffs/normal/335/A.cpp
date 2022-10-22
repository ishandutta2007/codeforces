#include <stdio.h>

using namespace std;

char s[1005];
int n;
int occ[128];
char ans[2010];

int main()
{
    scanf("%s%d", s, &n);
    for(int i=0; s[i]; occ[s[i++]]++);
    for(int i=1; s[i-1]; ++i){
        int left=n;
        bool ok=1;
        for(char j='a'; j <= 'z'; ++j){
            int a=(occ[j]+i-1)/i;
            int k;
            for(k=0; k < a && left; ++k)
                ans[--left]=j;
            if(k < a)
                ok=0;
        }
        for(int j=0; j < left; ++j)
            ans[j]='x';
        if(ok){
            ans[n]=0;
            printf("%d\n%s\n", i, ans);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}