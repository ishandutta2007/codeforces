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
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
int n,m;
map<int,int>M;
int main(){
	n=read();
	int a=read();
	vector<int>v1;
	for(int i=1;i<=n;i++)
		v1.push_back(read());
	m=read();
	a=read();
	vector<int>v2;
	for(int i=1;i<=m;i++)
		v2.push_back(read());
	//12,4,8,16,32114 
	int ans=0;
	M.clear();
	for(auto it:v1)
		M[it]++;
	for(auto it:v2)
		M[it]++;
	for(auto it:M)ans=max(ans,it.second);
	for(int l=1;l<=1e9;l*=2)
	{
		M.clear();
		for(auto it:v1)
			M[it%(l+l)]++;
		for(auto it:v2)
			M[(it+l)%(l+l)]++;
		for(auto it:M)ans=max(ans,it.second);
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}