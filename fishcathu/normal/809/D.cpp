#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3E5+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
mt19937 mtrand(time(0));
int val[N],key[N],lc[N],rc[N],laz[N],cnt;
int root,u,v;
void push(int i)
{
    if(!laz[i])return;
    val[i]+=laz[i];
    laz[lc[i]]+=laz[i];
    laz[rc[i]]+=laz[i];
    laz[i]=0;
}
void split(int i,int &x,int &y,int k)
{
    if(!i)x=y=0;
    else
    {
        push(i);
        if(val[i]<k)
        {
            x=i;
            split(rc[i],rc[i],y,k);
        }
        else
        {
            y=i;
            split(lc[i],x,lc[i],k);
        }
    }
}
int merge(int x,int y)
{
    if(!x||!y)return x|y;
    if(key[x]<key[y])
    {
        push(x);
        rc[x]=merge(rc[x],y);
        return x;
    }
    push(y);
    lc[y]=merge(x,lc[y]);
    return y;
}
int main()
{
    int ans=0;
    for(int n=read();n--;)
    {
        val[++cnt]=read();
        key[cnt]=mtrand();
        split(root,root,u,val[cnt]);
        split(u,u,v,read());
        ++laz[u];
        if(v)
        {
            int *p=&v;
            while(lc[*p])p=lc+*p;
            *p=merge(lc[*p],rc[*p]);
        }
        else ++ans;
        root=merge(root,merge(cnt,merge(u,v)));
    }
    write(ans,'\n');
}