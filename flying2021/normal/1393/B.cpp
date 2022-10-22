#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
int a[N];
int cnt[6];
char opt[3];
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int b;
        scanf("%d",&b);
        a[b]++;
    }
    scanf("%d",&m);
    for(int i=1;i<N;i++)
    {
        cnt[2]+=a[i]/4;
        cnt[1]+=(a[i]%4)/2;
    }
    for(int i=1;i<=m;i++)
    {
        int u;
        scanf("%s%d",opt,&u);
        if(opt[0]=='+')
        {
            cnt[2]-=a[u]/4;
            cnt[1]-=(a[u]%4)/2;
            a[u]++;
            cnt[2]+=a[u]/4;
            cnt[1]+=(a[u]%4)/2;
        }
        else
        {
            cnt[2]-=a[u]/4;
            cnt[1]-=(a[u]%4)/2;
            a[u]--;
            cnt[2]+=a[u]/4;
            cnt[1]+=(a[u]%4)/2;
        }
        puts(cnt[2] && (cnt[1]+cnt[2]>=3 || cnt[2]>=2)?"Yes":"No");
    }
    return 0;
}