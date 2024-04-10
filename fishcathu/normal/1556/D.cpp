#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E4+10;
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
int ask(int l,int r)
{
    printf("and %d %d\n",l,r);
    fflush(stdout);
    int res=read();
    printf("or %d %d\n",l,r);
    fflush(stdout);
    return res+read();
}
int a[N];
int main()
{
    int n=read(),m=read();
    ll s=0;
    s+=a[1]=ask(2,3);
    s+=a[2]=ask(1,3);
    s+=a[3]=ask(1,2);
    s>>=1;
    for(int i=1;i<=3;++i)a[i]=s-a[i];
    for(int i=4;i<=n;++i)a[i]=ask(1,i)-a[1];
    sort(a+1,a+1+n);
    printf("finish %d\n",a[m]);
}