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
const int N=5010;
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
char a[N],b[N],c[N];
void solve()
{
	scanf("%s%s",a,b);
	int n=strlen(a);
	memcpy(c,a,n);
	sort(c,c+n);
	int l=0;
	while(l<n&&a[l]==c[l])++l;
	if(l!=n)
	{
		int r=n;
		while(a[--r]!=c[l]);
		swap(a[l],a[r]);
	}
	puts(~strcmp(a,b)?"---":a);
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}