#include<stdio.h>
using namespace std;
int min[50],max[50],sol[50];
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int s,n,i,r=0;
    scanf("%d%d",&n,&s);
    for(i=1;i<=n;i++)
        scanf("%d%d",&min[i],&max[i]);
    for(i=1;i<=n;i++){
        sol[i]=max[i];
        r+=max[i];
    }
    if(r<s)
        printf("NO");
    else{
        i=n;
        while(r>s&&i>0)
            if(sol[i]!=min[i]){
                sol[i]--;
                r--;
            }
            else
                i--;
        if(r>s)
            printf("NO");
        else{
            printf("YES\n");
            for(i=1;i<=n;i++)
                printf("%d ",sol[i]);
        }
    }
    return 0;
}