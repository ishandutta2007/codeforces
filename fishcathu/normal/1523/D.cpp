#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb emplace_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=2E5,M=1<<15;
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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
char a[N][60];
int b[M],q[15],num[M];
bitset<60>ans;
int main()
{
    int n=read(),m=read();
    read();
    for(int i=0;i<n;++i)
    {
        scanf("%s",a[i]);
        for(int j=0;j<m;++j)a[i][j]&=1;
    }
    vct w(n);
    iota(w.begin(),w.end(),0);
    mt19937 rng(time(0));
    shuffle(w.begin(),w.end(),rng);
    w.erase(w.begin()+min(n,10),w.end());
    for(int i=1;i<M;++i)num[i]=num[i^i&-i]+1;
    int mx=0;
    for(int x:w)
    {
        int s=0;
        for(int i=0;i<m;++i)
        {
            if(a[x][i])
            {
                q[s++]=i;
            }
        }
        for(int i=0;i<n;++i)
        {
            int res=0;
            for(int j=0;j<s;++j)
            {
                if(a[i][q[j]])
                {
                    res|=1<<j;
                }
            }
            ++b[res];
        }
        s=1<<s;
        for(int i=2,j=1;i<=s;i<<=1,j<<=1)
        {
            for(int y=0;y<s;y+=i)
            {
                for(int z=0;z<j;++z)
                {
                    b[y+z]+=b[y+z+j];
                }
            }
        }
        for(int i=0,y=n+1>>1;i<s;++i)
        {
            if(b[i]<y)continue;
            if(num[i]>mx)
            {
                mx=num[i];
                ans=0;
                for(int j=__lg(s);j--;)
                {
                    if(i>>j&1)
                    {
                        ans[q[j]]=1;
                    }
                }
            }
        }
        memset(b,0,s<<2);
    }
    for(int i=0;i<m;++i)putchar(ans[i]|48);
}