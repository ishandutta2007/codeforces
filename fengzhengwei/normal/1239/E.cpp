#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<20],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
//s0,s1s0 
vector<int>s;
bitset<1250005>f[52][26];
multiset<int>TT;
vector<int>ans;
void run(int a,int b,int _s)
{
	if(!b)return;
	if(f[a-1][b][_s])return run(a-1,b,_s);
	return ans.push_back(s[a]),run(a-1,b-1,_s-s[a]);
}
int main(){
//	cout<<sizeof(f)/1024/1024<<"\n";
	int n=read();
	for(int i=1;i<=n;i++)s.push_back(read());
	for(int i=1;i<=n;i++)s.push_back(read());
	sort(s.begin(),s.end());
	for(auto it:s)TT.insert(it);
	f[0][0][0]=1;
	f[1][1][s[1]]=1;
	for(int i=1;i<s.size()-1;i++)
	{
		int T=s[i+1];
		for(int j=1;j<=n;j++)f[i+1][j]|=f[i][j];
		for(int j=1;j<n;j++)f[i+1][j+1]|=(f[i][j]<<T);
	}
	int ttsum=0;
	for(auto it:s)ttsum+=it;
	int Mn=1e9,id=0;
	for(int i=0;i<1250005;i++)
	{
		if(f[s.size()-1][n][i])
		{
			if(Mn>max(i+s[0],ttsum-i+s[1]))
				Mn=max(i+s[0],ttsum-i+s[1]),id=i;
		}
	}
	run(s.size()-1,n,id);
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	for(auto it:ans)TT.erase(TT.find(it));
	for(auto it:TT)cout<<it<<" ";
	puts("");
	for(auto it:ans)cout<<it<<" ";
	puts("");
//	cout<<Mn<<"\n"; 
	pc('1',1);
	return 0;
}