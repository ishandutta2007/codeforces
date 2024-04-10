#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int q[105], s[105];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i < n; ++i){
        scanf("%d", q+i);
        --q[i];
    }
    for(int i=0; i < n; ++i){
        scanf("%d", s+i);
        --s[i];
    }
    int congr[105], mod[105];
    for(int i=0; i < n; ++i){
        int moves=0, j=i;
        while(j != s[i]){
            j=q[j];
            ++moves;
            if(j == i){
                moves=-1;
                break;
            }
        }
        if(moves == -1){
            printf("NO");
            return 0;
        }
        congr[i]=moves;
        while(j != i || moves == 0){
            j=q[j];
            ++moves;
        }
        mod[i]=moves;
    }
    map<int, bool> possible;
    for(int K=-k; K <= k; ++K){
        bool ok=1;
        for(int i=0; i < n; ++i)
            if((K+mod[i]*105)%mod[i] != congr[i])
                ok=0;
        if(ok){
            possible[K]=true;
        }
        else
            possible[K]=false;
    }
    if(k > 0 && possible[0])
        printf("NO");
    else if(k > 1 && possible[1] && possible[-1])
        printf("NO");
    else{
        for(int K=-k; K <= k; K += 2)
            if(possible[K]){
                printf("YES");
                return 0;
            }
        printf("NO");
    }
    return 0;
}