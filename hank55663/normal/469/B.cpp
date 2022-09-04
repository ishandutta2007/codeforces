#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int game[101],n;
void output()
{
    for(int i=1;i<=n;i++)
    if(game[i]==0)
    {
        printf("Oh, my keyboard!\n");
        return;
    }
    printf("I become the guy.\n");
    return;


}
main()
{
int p,q,l,r,time[10001]={0},ans=0;
scanf("%d %d %d %d",&p,&q,&l,&r);
int x[100][2];
int y[100][2];
for(int i=0;i<p;i++)
{
    scanf("%d %d",&x[i][0],&x[i][1]);
    for(int j=x[i][0];j<=x[i][1];j++)
        time[j]=1;
}
for(int i=0;i<q;i++)
{
    scanf("%d %d",&y[i][0],&y[i][1]);
}
int suit;
for(int i=l;i<=r;i++)
{
    suit=0;
    for(int j=0;j<q;j++)
    {
        for(int k=y[j][0];k<=y[j][1];k++)
            if(time[k+i]==1)
            {
                suit=1;
                ans++;
                break;
            }
        if(suit==1)
            break;
    }

}
printf("%d\n",ans);
return 0;
}