#include<bits/stdc++.h>
#define ll long long
#define dd double
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
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
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
const int xx=3e5+5;
int n,k,a[xx],w[xx],vs[xx];

signed main(){
	n=read();
	ll k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)w[i]=read();
	multiset<pair<int,int> >s;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]%100==0)continue;
		k+=100-a[i]%100;
//		cout<<
		if(k>=100)k-=100,s.insert(make_pair(w[i]*(100-a[i]%100),i));
		else if(s.size()&&s.begin()->first<w[i]*(100-a[i]%100))ans+=s.begin()->first,s.erase(s.begin()),s.insert(make_pair(w[i]*(100-a[i]%100),i));
		else ans+=w[i]*(100-a[i]%100);
	}
	cout<<ans<<"\n";
	for(auto it:s)vs[it.second]=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]%100==0)cout<<a[i]/100<<" "<<0<<"\n";
		else 
		if(vs[i])cout<<a[i]/100<<" "<<a[i]%100<<"\n";
		else cout<<a[i]/100+1<<" "<<0<<"\n";
	}
	
	pc('1',1);
	return 0;
}