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
int main()
{
	int n=read(),ans=0;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)for(int j=0;j<30;++j)if(a[i]&1<<j)
	{
		int s=0;
		for(int k=i+1;k<n;++k)
		{
			s+=a[k];
			if(s>=1<<j+1)break;
			if(s<1<<j)continue;
			if(s==(a[i]^a[k+1]))++ans; 
		}
		s=0;
		for(int k=i-1;k>1;--k)
		{
			s+=a[k];
			if(s>=1<<j+1)break;
			if(s<1<<j)continue;
			if(s==(a[i]^a[k-1]))++ans; 
		}
	}
	write(ans);
}