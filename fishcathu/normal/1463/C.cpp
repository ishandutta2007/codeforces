#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
typedef long long ll;
const int N=1E5+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
pair<ll,ll>a[N];
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),ans=0;
		for(int i=1;i<=n;++i)a[i].l=read(),a[i].r=read();
		a[n+1].l=1ll<<62;
        a[n+1].r=a[n].r;
		for(int i=1,now=0;i<=n;)
		{
			int k=a[i].r>now?1:-1;
			int t=lower_bound(a+i+1,a+1+n,make_pair(a[i].l+abs(a[i].r-now),-1ll<<62))-a;
			for(int j=i;j<t;++j)
			{
				ll y=now+k*(a[j].l-a[i].l);
				ll z=now+k*(a[j+1].l-a[i].l);
				if(k==1)z=min(z,a[i].r);
				else z=max(z,a[i].r);
				if(a[j].r>=y&&a[j].r<=z||a[j].r<=y&&a[j].r>=z)++ans;
			}
			now=a[i].r;
			i=t;
		}
		printf("%d\n",ans);
	}
}