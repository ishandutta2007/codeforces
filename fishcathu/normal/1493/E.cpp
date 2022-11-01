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
const int N=1E6+10;
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
char a[N],b[N];
int n;
void add(char *c)
{
    int i=n;
    while(c[--i]==49)
    {
        c[i]=48;
    }
    c[i]=49; 
}
int main()
{
    n=read();
    scanf("%s%s",a,b);
    if(n!=1&&a[0]==48)
    {
        while(n--)putchar(49);
        return 0;
    }
    if(b[n-1]==48)
    {
        add(a);
        if(strcmp(a,b)<0)add(b);  
    }
    puts(b);
}