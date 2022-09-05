#include<cstdio>
#include<cstring>
using namespace std;
int maxi,x,y,S,x1,x2,x3,x4,i,j,I,n,R,dp[109][2][2][2][2],ap[209],a[109][5];
void set1(int n,int x1,int x2,int x3,int x4)
{
    ap[dp[n][x1][x2][x3][x4]]=1;
}
void bg(int x,int y)
{
    if(x>=1&&x<=R&&y>=1&&y<=2) a[x][y]=1;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&R);
scanf("%d",&n);
S=0;
dp[0][0][0][0][1]=1;
dp[0][0][0][1][0]=1;
dp[0][0][1][0][0]=1;
dp[0][1][0][0][0]=1;
dp[0][1][0][0][1]=1;
dp[0][0][1][1][0]=1;

for(x1=0;x1<=1;x1++)
    for(x2=0;x2<=1;x2++)
        for(x3=0;x3<=1;x3++)
            for(x4=0;x4<=1;x4++)
            {
                if(x1*x2!=0||x3*x4!=0) continue;
                if(x1*x4||x2*x3) dp[1][x1][x2][x3][x4]=0;
                else
                if(x1+x2+x3+x4==1) dp[1][x1][x2][x3][x4]=2;
                else dp[1][x1][x2][x3][x4]=1;
            }
for(i=2;i<=R;i++)
    for(x1=0;x1<=1;x1++)
        for(x2=0;x2<=1;x2++)
            for(x3=0;x3<=1;x3++)
                for(x4=0;x4<=1;x4++)
                    if(x1*x2==0&&x3*x4==0)
                    {
                        memset(ap,0,sizeof(ap));
                        if(x1)
                        {
                            set1(i-1,x1,x2,x3,x4);
                            ap[dp[i-2][x1][x2][x3][x4]^1]=1;
                            set1(i-2,0,1,x3,x4);
                        }
                        else
                        if(x2)
                        {
                            set1(i-1,x1,x2,x3,x4);
                            ap[dp[i-2][x1][x2][x3][x4]^1]=1;
                            set1(i-2,1,0,x3,x4);
                        }
                        else
                        {
                            set1(i-2,0,1,x3,x4);
                            set1(i-2,1,0,x3,x4);
                        }
                        if(x3)
                        {
                            set1(i-1,x1,x2,x3,x4);
                            ap[dp[i-2][x1][x2][x3][x4]^1]=1;
                            set1(i-2,x1,x2,0,1);
                        }
                        else
                        if(x4)
                        {
                            set1(i-1,x1,x2,x3,x4);
                            ap[dp[i-2][x1][x2][x3][x4]^1]=1;
                            set1(i-2,x1,x2,1,0);
                        }
                        else
                        {
                            set1(i-2,x1,x2,0,1);
                            set1(i-2,x1,x2,1,0);
                        }
                        for(I=2;I<i;I++)
                        {
                            ap[dp[I-2][x1][x2][1][0]^dp[i-I-1][1][0][x3][x4]]=1;
                            ap[dp[I-2][x1][x2][0][1]^dp[i-I-1][0][1][x3][x4]]=1;
                        }
                        for(j=0;j<=1000;j++)
                            if(ap[j]==0) break;
                        dp[i][x1][x2][x3][x4]=j;
                        if(j>maxi) maxi=j;
                    }
for(i=1;i<=n;i++)
{
    scanf("%d",&x);
    scanf("%d",&y);
    bg(x,y);
    bg(x,3-y);
    bg(x-1,3-y);
    bg(x+1,3-y);
}
for(i=1;i<=R;i++)
{
    if(a[i][1]&&a[i][2]) continue;
    x1=x2=x3=x4=0;
    if(a[i][1]==0) x1=1;
    if(a[i][2]==0) x2=1;
    j=i+1;
    while(a[j][1]==0&&a[j][2]==0&&j<=R)
        j++;
    I=j-i-1;
    if(a[j][1]==0) x3=1;
    if(a[j][2]==0) x4=1;
    if(x1==1&&x2==1)
    {
        I++;
        x1=x2=0;
    }
    if(x3*x4) x3=x4=0;
    S^=dp[I][x1][x2][x3][x4];
    i=j;
}
if(S==0)
{
    printf("LOSE\n");
    return 0;
}
printf("WIN\n");
return 0;
}