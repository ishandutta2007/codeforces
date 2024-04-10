#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int n,a[1005][1005];

int main()
{
    scanf("%d",&n);
    puts("+------------------------+");
    int i=1,j=1;
    for(int x=1;x<=n;)
    {
        if(j>1 && i==3)
        {
            i++;
            continue;
        }else
        {
            ++x;
            a[i][j]=1;
            i++;
            if(i>4){j++;i=1;}
        }
    }
    for(int i=1;i<=4;i++)
    {
        printf("|");
        if(i==3)
        {
            if(a[3][1])printf("O");else printf("#");
            for(int j=1;j<=23;j++)printf(".");
            printf("|");
        }
        else
        {
            for(int j=1;j<=11;j++) printf("%c.",(a[i][j])?('O'):('#'));
            if(i==1)printf("|D|)");else
            if(i==2)printf("|.|");else
            if(i==4)printf("|.|)");
        }
        puts("");
    }
    puts("+------------------------+");
    return 0;
}