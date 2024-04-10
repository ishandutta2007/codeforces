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
    int c,d;
    scanf("%d",&n);
    scanf("%d",&c);
    for(int i=1;i<101;i++)
        game[i]=0;
    for(int i=0;i<c;i++)
    {
        int a;
        scanf("%d",&a);
        game[a]=1;
    }
    scanf("%d",&d);
    for(int i=0;i<d;i++)
    {
        int a;
        scanf("%d",&a);
        game[a]=1;
    }
    output();
return 0;
}