#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e5+5;
char s[xx];
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
		map<char ,int>mp;
		for(int i=1;i<=n+n;i++)
		{
			char c;while((c=getchar())!='0'&&c!='1');
			s[i]=c,mp[c]++;
		}
		int cr=1;
		for(auto &it:mp)if(it.second&1)cr=0;
		if(!cr)
		{
			puts("-1");
			continue;
		}
		vector<int>cg;
		int nw=0;
		for(int i=1;i<=n+n;i+=2)
		{
			if(s[i]!=s[i+1])
			{
				if(s[i]-'0'==nw)cg.push_back(i);
				else cg.push_back(i+1);
				nw^=1;
			}
		}
		cout<<cg.size()<<" ";
		for(auto it:cg)cout<<it<<" ";
		puts("");
		for(int i=1;i<=n+n;i+=2)cout<<i<<" ";
		puts("");
	}
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}