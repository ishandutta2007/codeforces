#include <stdio.h>
#include <string.h>
int main(){
    //freopen("in.txt","r",stdin);
    int light[105];
    int n,m;
    while(scanf("%d %d ",&n,&m)!=EOF){
        memset(light,-1,sizeof(light));
        while(m--){
            int bi,i;
            scanf("%d ",&bi);
            i=bi;
            while(i<=n){
                if(light[i] == -1){
                    light[i]=bi;
                }
                i++;
            }
        }
        int j=1;
        while(j<=n){
            printf("%d ",light[j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}