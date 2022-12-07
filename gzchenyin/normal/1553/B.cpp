#include<cstdio>
#include<cstring>
using namespace std;
int n,m,T;
char s[1005],t[1005];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        scanf("%s",t+1);
        n=strlen(s+1);
        m=strlen(t+1);
        bool ans=false;
        for(int Pos=1;Pos<=m;Pos++)
        {
            for(int i=1;i<=n;i++)
            {
                bool flag=true;
                for(int j=1;j<=Pos;j++)
                {
                    if(j+i-1>n || s[j+i-1]!=t[j])
                    {
                        flag=false;
                        break;
                    }
                }//i~i+Pos-1
                for(int j=1;j<=m-Pos;j++)
                {
                    if((i+Pos-1)-j<=0 || s[(i+Pos-1)-j]!=t[j+Pos])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag) ans=true;
            }
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
}