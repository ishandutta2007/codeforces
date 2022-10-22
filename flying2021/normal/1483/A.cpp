#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 100010
using namespace std;
vector<int>a[N];
int b[N],c[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int lim=(m+1)/2;
        for(int i=1;i<=m;i++)
        {
            int k;
            scanf("%d",&k);
            a[i].resize(k);
            for(int j=0;j<k;j++) scanf("%d",&a[i][j]);
            b[i]=a[i][0];c[b[i]]++;
        }
        int id=0;
        for(int i=1;i<=n;i++)
        if(c[i]>lim){id=i;break;}
        if(!id)
        {
            puts("YES");
            for(int i=1;i<=m;i++) printf("%d ",b[i]);
            puts("");
        }
        else
        {
            for(int i=1;i<=m;i++)
            if(a[i][0]==id && a[i].size()>1)
            {
                b[i]=a[i][1];
                c[id]--;
                if(c[id]<=lim) break;
            }
            if(c[id]>lim) puts("NO");
            else
            {
                puts("YES");
                for(int i=1;i<=m;i++) printf("%d ",b[i]);
                puts("");
            }
        }
        for(int i=1;i<=n;i++) c[i]=b[i]=0;
    }
    return 0;
}