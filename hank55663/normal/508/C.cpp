#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<map>
#include<string.h>
using namespace std;
main(){
    int m,t,r;
    scanf("%d %d %d",&m,&t,&r);
    int ghost[900];
    int time[900];
    for(int i=0;i<900;i++)
        time[i]=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&ghost[i]);
    }
    if(r>t)
        printf("-1");
    int ans=0;
    if(r<=t){
    for(int i=0;i<m;i++)
    {
        int ok=1;
        for(int x=ghost[i];0<r-time[ghost[i]];x--)
        {
            ans++;
            for(int k=0;k<t;k++)
            if(k+x>=0)
            time[k+x]++;
        }
        if(!ok)
        {
            printf("-1");
            return 0;
        }
    }
    printf("%d",ans);}
    return 0;
}