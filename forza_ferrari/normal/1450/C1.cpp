#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[3],b[3],ans,tag;
char mp[301][301];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        a[0]=a[1]=a[2]=b[0]=b[1]=b[2]=0;
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=n;++j)
            {
                mp[i][j]=getchar();
                if(mp[i][j]!='X'&&mp[i][j]!='O'&&mp[i][j]!='.')
                    mp[i][j]=getchar();
                if(mp[i][j]=='X')
                    ++a[(i+j)%3];
                if(mp[i][j]=='O')
                    ++b[(i+j)%3];
            }
        tag=0;
        for(register int i=1;i<3;++i)
                if(a[i]+b[(i+1)%3]<a[tag]+b[(tag+1)%3])
                    tag=i;
        for(register int i=1;i<=n;++i,puts(""))
            for(register int j=1;j<=n;++j)
            {
                if(mp[i][j]=='X'&&(i+j)%3==tag)
                    mp[i][j]='O';
                else
                    if(mp[i][j]=='O'&&(i+j)%3==(tag+1)%3)
                        mp[i][j]='X';
                putchar(mp[i][j]);
            }
    }
    return 0;
}