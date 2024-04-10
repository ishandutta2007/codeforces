#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2E5+5;
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
int a[N],l[N],r[N],head[N],nex[N];
int getsum(int x)
{
    int sum=0;
    while(x)sum+=a[x],x-=x&-x;
    return sum;
}
int main()
{
    for(int x=read();x--;)
    {
        int n=read();
        for(int i=1;i<=n;++i)a[i]=l[i]=read(),head[i]=0;
        sort(l+1,l+1+n);
        int s=unique(l+1,l+1+n)-l-1;
        for(int i=1;i<=n;++i)a[i]=lower_bound(l+1,l+1+s,a[i])-l;
        for(int i=1,mx=1;i<=n;++i)
        {
            if(a[i]>mx)
            {
                for(int j=a[i];--j>=mx;)l[j]=i;
                mx=a[i];
            }
            nex[i]=head[a[i]],head[a[i]]=i;
        }
        for(int i=n,mx=1;i;--i)if(a[i]>mx)
        {
            for(int j=a[i];--j>=mx;)r[j]=i;
            mx=a[i];
        }
        for(int i=1;i<=n;++i)a[i]=0;
        int i=nex[head[s]];
        if(nex[i]){puts("YES"),printf("%d %d %d\n",i-1,1,n-i);continue;} 
        for(i=1;i<s;++i)
        {
            if(getsum(l[i])==getsum(r[i]))
            {
                int j=head[i];
                while(j&&j<r[i])j=nex[j];
                do
                {
                    j=nex[j];
                    if(j==r[i]+1)++r[i];
                    else if(j==l[i]-1)--l[i];
                }while(j&&(j<l[i]||j>r[i]));
                do j=nex[j];while(j&&j>l[i]);
                if(j)
                {
                    puts("YES"),printf("%d %d %d\n",l[i]-1,r[i]-l[i]+1,n-r[i]);
                    break;
                }
            }
            for(int j=head[i];j;j=nex[j])for(int k=j;k<=n;k+=k&-k)++a[k];
        }
        if(i==s)puts("NO");
    }
    return 0;
}