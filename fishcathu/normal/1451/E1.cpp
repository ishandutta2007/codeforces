#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=1E5+10;
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
struct st
{
	int l,r;
	bool operator<(const st m)const{return l<m.l;}
}a[N];
int ans[N];
int ask(int l,int r,string a)
{
	cout<<a<<' '<<l<<' '<<r<<endl;
	cout.flush();
	return read();
}
int main()
{
	int n=read();
	for(int i=2;i<=n;++i)a[i].l=ask(1,i,"XOR"),a[i].r=i;
	sort(a+2,a+1+n);
	if(!a[2].l)ans[1]=ask(1,a[2].r,"OR");
	else
	{
		int i=2;
		while(i<n&&a[i].l!=a[i+1].l)++i;
		if(i<n)ans[1]=a[i].l^ask(a[i].r,a[i+1].r,"OR");
		else
		{
			i=2;
			while(i<=n&&a[i].l!=1)++i;
			if(i>n)ans[1]=n-1;
			else
			{
				int t=ask(1,a[i].r,"AND");
				i=2;
				while(i<=n&&a[i].l&1)++i;
				ans[1]=t|ask(1,a[i].r,"AND")&1;
			}
		}
	}
	for(int i=2;i<=n;++i)ans[a[i].r]=ans[1]^a[i].l;
	putchar('!');
	for(int i=1;i<=n;++i)putchar(' '),write(ans[i]);
	return 0;
}