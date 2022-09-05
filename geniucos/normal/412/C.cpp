#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int i,j,n,m,ap[100009][30];
char sir[100009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d\n",&n);
for(i=1;i<=n;i++)
{
    gets(sir+1);
    m=strlen(sir+1);
    for(j=1;j<=m;j++)
    {
        if(sir[j]=='?') ap[j][0]++;
        else ap[j][sir[j]-'a'+1]++;
    }
}
for(j=1;j<=m;j++)
{
    if(ap[j][0]==n) printf("x");
    else
    {
        for(i='a';i<='z';i++)
            if(ap[j][i-'a'+1]+ap[j][0]==n) break;
        if(i<='z') printf("%c",i);
        else printf("?");
    }
}
printf("\n");
return 0;
}