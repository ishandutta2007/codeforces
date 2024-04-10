#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn=2010;
int t[maxn],h[maxn],m[maxn];
bool used[maxn];
int main()
{
    int n,x;
    while (scanf("%d%d",&n,&x)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d%d%d",&t[i],&h[i],&m[i]);
        int ans=0;
        for (int i=0;i<2;i++) 
        {
            memset(used,false,sizeof(used));
            int curx=x;
            int curtype=i;
            int curid=0;
            int curans=0;
            while (true)
            {
                int curm=-1;
                for (int j=0;j<n;j++)
                {
                    if (!used[j]&&t[j]==curtype&&curx>= h[j]&&curm<=m[j])
                    {
                        curm=m[j];  
                        curid=j;     
                    }
                }
                if (curm==-1)  break;
                used[curid]=true;  
                curans++;         
                curx+=curm;     
                curtype^=1;   
            }
            ans = max(ans,curans);
        }
        printf("%d\n",ans);
    }
}