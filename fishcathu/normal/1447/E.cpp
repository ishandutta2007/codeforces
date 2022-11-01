#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2E5+10;
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
int a[N];
int geth(int x)
{
	while(x&x-1)x&=x-1;
	return x;
}
int getans(int l,int r)
{
	if(a[l]==a[r])return r-l+1;
	int b[35]={0},s=1,ans=0;
	b[1]=1;
	for(int i=l+1;i<=r;++i)
	{
		if((a[i]&a[i-1])>a[i]>>1)++b[s];
		else b[++s]=1;
	}
	for(int i=s;i;--i)
	{
		int t=geth(a[r-b[i+1]]);
		for(int j=r-b[i+1];j>r-b[i+1]-b[i];--j)a[j]-=t;
		ans=max(ans,getans(r-b[i+1]-b[i]+1,r-b[i+1])+s-i+(i!=1));
		b[i]+=b[i+1];
	}
	return ans;
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	write(n-getans(1,n));
	return 0;
}