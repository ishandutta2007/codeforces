#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;else if(c==EOF)return -1;
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
const int xx=1e5+5;
char s[xx];
int b[xx],t[xx],n,num;
signed main(){
	n=read();
	scanf("%s",s+1);
	ll ans=0;
	for(int i=1;i<=n;i++)b[i]=read(),ans+=b[i];
	for(int i=1;i<=n/2;i++)
		if(s[i]==s[n-i+1])ans-=min(b[i],b[n-i+1]),t[s[i]-'a']++,num++;
	int id=-1;
	for(int i=0;i<26;i++)if(t[i]*2>num)id=i;
	if(id!=-1)
	{
		multiset<int>c;
		for(int i=1;i<=n/2;i++)
			if(s[i]!=s[n-i+1]&&s[i]-'a'!=id&&s[n-i+1]-'a'!=id)c.insert(min(b[i],b[n-i+1]));
		t[id]-=(num-t[id]);
		while(t[id]--)ans-=*c.begin(),c.erase(c.begin());
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}