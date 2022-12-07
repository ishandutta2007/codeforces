#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char a[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a+1);
        int len=strlen(a+1),ans=1;
        for(int j=1;j<=len;j++)
        {
            if(a[j]>'1') ans=max(ans,a[j]-'1'+1);
        }
        printf("%d\n",ans);
    }
}