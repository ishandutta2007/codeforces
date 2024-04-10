#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int TC;
    scanf("%d\n",&TC);
    int n,k;
    int a,b;
    int best;
    int diff;
    int ans;
    while (TC--){
        best=0;
        diff=0;
        scanf("%d%d",&n,&k);
        while (n--){
            scanf("%d%d",&a,&b);
            diff=max(diff,a-b);
            best=max(a,best);
        }
        if (k<=best){
            printf("1\n");
        }
        else{
            if (diff>0){
                printf("%d\n", (k-best-1) /diff+2);
            }
            else{
                printf("-1\n");
            }
        }
    }
}