#include<bits/stdc++.h>
#define maxn 5050

using namespace std;
int s[maxn],s2[maxn],a[maxn],b[maxn],ans[maxn],n,k,t,cnt;
bool f;

int main()
{
    scanf("%d",&n);cnt=0;
    for (int i=0;i<n;i++)
    {
        printf("? %d 0\n",i);
        fflush(stdout);
        scanf("%d",&s[i]);
    }
    for (int i=0;i<n;i++)
    {
        printf("? 0 %d\n",i);
        fflush(stdout);
        scanf("%d",&s2[i]);
    }
    for (int i=0;i<n;i++)
    {
        a[0]=i;t=s[0]^a[0];f=true;
        memset(b,-1,sizeof(b));
        b[a[0]]=0;
        for (int j=1;j<n;j++)
        {
            a[j]=s[j]^t;
            if (a[j]>=n||b[a[j]]>=0) f=false;
            b[a[j]]=j;
        }
        for (int j=0;j<n;j++) if ((a[0]^b[j])!=s2[j]) f=false;
        if (f&&b[0]==t){
            cnt++;
            for (int j=0;j<n;j++) ans[j]=a[j];
        }
    }
    printf("!\n");
    printf("%d\n",cnt);
    for (int i=0;i<n;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}