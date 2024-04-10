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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
char a[N];
const char f[4]={'T','A','N','O'};
void solve()
{
    scanf("%s",a+1);
    int n=strlen(a+1);
    int s[4]={0};
    for(int i=1;i<=n;++i)++s[a[i]&=3];
    char ans[4];
    ll mx=-1;
    for(char b[4]={0,1,2,3};1;)
    {
        ll res=0;
        int q[4]={0};
        for(int i=1;i<=n;++i)
        {
            char x=b[a[i]];
            for(int j=0;j<x;++j)++q[j];
            res+=q[x];
        }
        if(res>mx)
        {
            mx=res;
            for(int i=0;i<4;++i)ans[b[i]]=i;
        }
        if(!next_permutation(b,b+4))break;
    }
    for(int i=0;i<4;++i)
    {
        char x=ans[i];
        while(s[x]--)putchar(f[x]);
    }
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}