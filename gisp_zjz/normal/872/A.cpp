#include<bits/stdc++.h>
#define maxn 200020

using namespace std;

int s,t,a[10],b[10],k;
bool f,g;

int main()
{
    scanf("%d%d",&s,&t);
    memset(a,false,sizeof(a));
    memset(b,false,sizeof(b));
    while (s--)
    {
        scanf("%d",&k);a[k]=true;
    }
    while (t--)
    {
        scanf("%d",&k);b[k]=true;
    }
    for (int i=1;i<10;i++)
        if (a[i]&&b[i]){
            printf("%d\n",i);
            return 0;
        }
    f=g=true;
    for (int i=1;i<10;i++){
        if (a[i]&&f){printf("%d",i);f=false;}
        if (b[i]&&g){printf("%d",i);g=false;}
    }
    printf("\n");return 0;
}