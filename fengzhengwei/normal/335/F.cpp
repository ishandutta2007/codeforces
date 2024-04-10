#include<bits/stdc++.h>
#define ll long long
#define dd long double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
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
const int xx=5e5+5;
int n,a[xx];
multiset<int>s;
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(a[j+1]==a[j])j++;
		assert(i-1>=(int)s.size()*2);
		int num=j-i+1,rem=max(0,num-(i-1-(int)s.size()*2));
		vector<int>v;
		for(int k=1;k<=num-rem;k++)v.push_back(a[i]);
		for(int k=1;k<=rem;k+=2)
		{
			if(!s.size())continue;
			int I=*s.begin();
			s.erase(s.begin());
			if(a[i]>I)
			{
				v.push_back(a[i]);
				if(k!=rem)v.push_back(a[i]);
			}
			else 
			{
//		cout<<i<<" "<<a[i]<<" "<<rem<<" "<<I<<" "<<a[i]+a[i]-I<<" "<<k<<"!!\n";
				v.push_back(I);
				if(k!=rem&&a[i]+a[i]-I>0)v.push_back(a[i]+a[i]-I);
			}
		}
		for(auto it:v)s.insert(it);
		i=j;
	}
//	for(auto it:s)cout<<it<<" ";
//	puts("");
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=a[i];
	for(auto it:s)ans-=it;
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}