#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=110;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(!(c&16));
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
    return a*b; 
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
char a[N][N];int ans[5010][6],s;
void sv(int i,int j,int k)
{
    a[ans[++s][0]=i][ans[s][1]=j]=!a[i][j];
    if(k==1)a[ans[s][2]=i][ans[s][3]=j-1]=!a[i][j-1],a[ans[s][4]=i-1][ans[s][5]=j]=!a[i-1][j];
    else if(k==2)a[ans[s][2]=i][ans[s][3]=j+1]=!a[i][j+1],a[ans[s][4]=i-1][ans[s][5]=j]=!a[i-1][j];
    else if(k==3)a[ans[s][2]=i][ans[s][3]=j-1]=!a[i][j-1],a[ans[s][4]=i+1][ans[s][5]=j]=!a[i+1][j];
    else a[ans[s][2]=i][ans[s][3]=j+1]=!a[i][j+1],a[ans[s][4]=i+1][ans[s][5]=j]=!a[i+1][j];
}
void sv1(int i,int j)
{
    if(a[i][j]&&a[i+1][j])sv(i,j,4);
    else if(a[i][j])sv(i,j+1,3);
    else if(a[i+1][j])sv(i+1,j+1,1);
}
void sv2(int i,int j)
{
    if(a[i][j]&a[i][j-1])sv(i,j,3);
    else if(a[i][j])sv(i+1,j,1);
    else if(a[i][j-1])sv(i+1,j-1,2);
}
void sv3(int i,int j)
{
    if(a[i][j]&a[i][j-1])sv(i-1,j,3),sv(i-1,j-1,4);
    else if(a[i][j])sv(i-1,j,3),sv(i,j,1),sv(i,j-1,2);
    else if(a[i][j-1])sv(i-1,j-1,4),sv(i,j,1),sv(i,j-1,2);
}
int main()
{
    for(int x=read();x--;)
    {
        int n=read(),m=read();
        s=0;
        for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]&=1;
        for(int i=1;i<=n;i+=2)
        {
            if(i==n)--i;
            for(int j=1;j<m-1;++j)sv1(i,j);
        }
        for(int i=1;i<n;++i)sv2(i,m);
        sv3(n,m);
        printf("%d\n",s);
        for(int i=1;i<=s;++i)for(int j=0;j<6;++j)printf("%d%c",ans[i][j],j==5?'\n':' '); 
    } 
}