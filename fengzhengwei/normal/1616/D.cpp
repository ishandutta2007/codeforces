#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
//char s[xx];
int a[xx];
ll sum[xx];
int f[xx];
multiset<ll>s;
bool check(ll now)
{
	if(*--s.end()>now)return 1;
	return 0;
}
int main(){
	int T=read();
	while(T--)
	{
		s.clear();
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int x=read();
		for(int i=1;i<=n;i++)a[i]-=x;
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		int L=1;
		s.insert(0);
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1];
			s.insert(sum[i]);
			s.erase(s.find(sum[i-1]));
			while(L<i&&check(sum[i]))
			{
				s.erase(s.find(sum[L-1]));
				L++;
			}
			s.insert(sum[i-1]);
			f[i]=max(f[i],f[max(0,L-2)]+i-L+1);
//			cout<<i<<" "<<L<<" "<<i<<" "<<f[i]<<"qwe\n";
		}
		cout<<f[n]<<"\n";
	}
	pc('1',1);
	return 0;
}