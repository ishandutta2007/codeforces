#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=1E5+10;
const int inf=1<<30;
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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],q[N];
bitset<N>b;
const int c[2][2]={1,1,-1,1};
bool check(int l,int r,int s)
{
    return ~l&&l<s&&~r&&r<s;
}
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=m;++i)a[i]=read();
    int w=max_element(a+1,a+1+m)-a;
    int s=0;
    while((s+1)/2*(s+s/2)<n||((s+1)/2)*s<a[w])++s;
    for(int i=w,j=0;i<=m;)
    {
        while(a[i])
        {
            q[++j]=i;
            b[j]=0;
            --a[i];
        }
        if(i==w)i=0;
        if(++i==w)++i;
    }
    vector<vct>ans(s,vct(s));
    for(int i=0,k=1;1;)
    {
        for(int j=i&1^1;j<s&&k<=n;j+=2,++k)
        {
            if(i&1)
            {
                for(int p=2;p--;)
                {
                    int y=i+c[p][0],z=j+c[p][1];
                    if(check(y,z,s))
                    {
                        while(q[k]==ans[y][z])++k;
                    }
                }
                if(k>n)break;
            }
            ans[i][j]=q[k];
            b[k]=1;
        }
        if(k>n)break;
        i+=2;
        if(i>=s)
        {
            if(i&1||s==1)break;
            i=1;
        }
    }
    for(int i=0,k=1;i<s&&k<=n;i+=2)
    {
        for(int j=0;j<s;j+=2)
        {
            while(k<=n&&b[k])++k;
            if(k>n)break;
            ans[i][j]=q[k];
            b[k]=1;
        }
    }
    write(s,'\n');
    for(vct x:ans)
    {
        for(int t:x)
        {
            write(t,' ');
        }
        putchar('\n');
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}