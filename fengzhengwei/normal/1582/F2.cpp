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
const int xx=1e6+5;
int a[xx];
vector<int>p[8194];
int n,s[8194];
bitset<8194>vs;
int main(){
	for(int i=0;i<=8191;i++)s[i]=1e9;
	s[0]=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		p[a[i]].push_back(i);
	}
	vs[0]=1;
	for(int i=1;i<=5000;i++)
	{
//		int x=
		for(int j=vs._Find_first();j!=8194;j=vs._Find_next(j))
		{
//			if(s[j]!=1e9)
//			{
				vector<int>::iterator it=lower_bound(p[i].begin(),p[i].end(),s[j]);
				if(it!=p[i].end())
				{
					s[j^i]=min(s[j^i],*it);
					vs[j^i]=1;
				}
//			}
		}
	}
	int ss=0;
	for(int i=0;i<=8191;i++)
	{
		if(s[i]!=1e9)ss++;
	}
	cout<<ss<<"\n";
	for(int i=0;i<=8191;i++)
	{
		if(s[i]!=1e9)
		cout<<i<<" ";
	}
	puts("");
//	cout<<s[8]<<"ss\n";
	return 0;
}