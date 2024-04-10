#include<stdio.h>
#include<math.h>
#include<map>
#include<algorithm>
#include<string.h>
#define SIZE 300000
using namespace std;
main(){

int n;
scanf("%d",&n);
int a;
scanf("%d",&a);
char ans[10000];
for(int i=0;i<10000;i++)
    ans[i]=0;
int i;
for(i=0;a>9;i++,a-=9)
{
    ans[i]='9';
}
ans[i]='0'+a;
for(i=strlen(ans)-1;i>=0;i--)
printf("%c",ans[i]);
printf("\n");
for(i=0;i<n-1;i++)
{
    scanf("%d",&a);
    ans[0]++;
    for(int j=0;ans[j]>'9';j++)
            {
                ans[j]='0';
                if(ans[j+1]==0)
                    ans[j+1]='1';
                else
                    ans[j+1]++;
            }
    int sum=0;
    for(int j=0;j<strlen(ans);j++)
        sum+=ans[j]-'0';
    if(sum<=a)
    sum=a-sum;
    else
    {
        for(int j=0;j<strlen(ans);j++)
        {
            sum-=ans[j]-'0';
            sum++;
            ans[j]='0';
            if(ans[j+1]==0)
                ans[j+1]='0';
            ans[j+1]++;
            for(int k=j+1;ans[k]>'9';k++)
            {
                ans[k]='0';
                sum-=9;
                if(ans[k+1]==0)
                    ans[k+1]='1';
                else
                    ans[k+1]++;
            }
            if(sum<=a)
                break;
        }
        sum=a-sum;
    }
    for(int j=0;sum!=0;j++)
    {
        if(ans[j]==0)
            ans[j]='0';
        if(sum>'9'-ans[j])
        {sum-='9'-ans[j];
        ans[j]='9';}
        else
        {ans[j]+=sum;
        break;}
    }

for(int j=strlen(ans)-1;j>=0;j--)
printf("%c",ans[j]);
printf("\n");
}
    return 0;
}