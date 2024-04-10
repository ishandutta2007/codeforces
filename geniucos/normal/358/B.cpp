#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int nr,i,j,n,l;
char B[100009],A[100009],sir[100009];
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int det(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return mod(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d\n",&n);
for(i=1;i<=n;i++)
{
    gets(A+1);
    l=strlen(A+1);
    nr++;
    B[nr]='<';
    nr++;
    B[nr]='3';
    for(j=1;j<=l;j++)
    {
        nr++;
        B[nr]=A[j];
    }
}
nr++;
B[nr]='<';
nr++;
B[nr]='3';
scanf("\n");
gets(sir+1);
n=strlen(sir+1);
j=1;
for(i=1;i<=nr;i++)
{
    while(B[i]!=sir[j]&&j<=n)
    {
        if(sir[j]!='<'&&sir[j]!='>'&&sir[j]<'0'&&sir[j]>'9')
        {
            printf("no\n");
            return 0;
        }
        j++;
    }
    if(B[i]!=sir[j])
    {
        printf("no\n");
        return 0;
    }
    j++;
}
printf("yes\n");
return 0;
}