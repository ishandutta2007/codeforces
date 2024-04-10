#include <stdio.h>
#include <algorithm>

using namespace std;

char s[105];
long long test[4][2]={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
long long total[2], pos[2];

int getType(char i){
    int j;
    if(i == 'U')
        j=0;
    if(i == 'D')
        j=1;
    if(i == 'L')
        j=2;
    if(i == 'R')
        j=3;
    return j;
}

int main()
{
    long long a[2];
    scanf("%I64d%I64d", a, a+1);
    scanf("%s", s);
    total[0]=0; total[1]=0;
    for(int i=0; s[i]; ++i){
        int j = getType(s[i]);
        total[0] += test[j][0];
        total[1] += test[j][1];
    }
    pos[0]=0; pos[1]=0;
    for(int i=0; s[i]; ++i){
        for(int j=0; j < 2; ++j){
            if(total[j] == 0){
                if(pos[j] != a[j])
                    continue;
                if(total[1-j] == 0){
                    if(pos[1-j] != a[1-j])
                        continue;
                    printf("Yes");
                    return 0;
                }
                continue;
            }
            long long times = (a[j]-pos[j])/total[j];
            if(times < 0)
                continue;
            if(total[j]*times != a[j]-pos[j] || total[1-j]*times != a[1-j]-pos[1-j])
                continue;
            printf("Yes");
                    return 0;
        }
        int k=getType(s[i]);
        pos[0] += test[k][0];
        pos[1] += test[k][1];
    }
    printf("No");
    return 0;
}