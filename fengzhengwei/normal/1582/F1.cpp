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
const int xx=1e5+5;
int a[xx];
vector<int>p[558];
int n;
int s[558];
int main(){
	for(int i=0;i<=555;i++)s[i]=1e9;
	s[0]=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		p[a[i]].push_back(i);
	}
	for(int i=1;i<=555;i++)
	{
		for(int j=0;j<=555;j++)
		{
			if(s[j]!=1e9)
			{
				vector<int>::iterator it=lower_bound(p[i].begin(),p[i].end(),s[j]);
				if(it!=p[i].end())
				{
//					if((j^i)==8)
//					{
//						cout<<i<<" "<<j<<"\n";
//					}
					s[j^i]=min(s[j^i],*it);
				}
			}
		}
	}
	int ss=0;
	for(int i=0;i<=555;i++)
	{
		if(s[i]!=1e9)ss++;
	}
	cout<<ss<<"\n";
	for(int i=0;i<=555;i++)
	{
		if(s[i]!=1e9)
		cout<<i<<" ";
	}
	puts("");
//	cout<<s[8]<<"ss\n";
	return 0;
}