#include<bits/stdc++.h>
#define ll long long
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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=1e5+5;
char s[xx];
int n,to[xx],is[xx],q[xx<<1],l,r,nx[xx],ndf[xx];
vector<int>id;
// 
int main(){
//	freopen("a.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=n;i>=1;i--)
	{
		if(s[i]!=s[i+1])
		{
			to[i]=s[i],nx[i]=i;
			if(to[i+1]!=s[i])ndf[i]=to[i+1];
			else ndf[i]=ndf[nx[i+1]];
		}
		else if(s[i]==s[i+1])
		{
//			if(i==1)
//			{
//				cout<<nx[i+2]<<" "<<char(ndf[nx[i+2]])<<" "<<(to[i+2]<s[i]||(to[i+2]==s[i]&&ndf[nx[i+2]]<s[i]))<<"ASDDF\n"; 
//			}
			if((to[i+2]<s[i]||(to[i+2]==s[i]&&ndf[nx[i+2]]<s[i]))&&!is[i+1])
			{
//				cout<<i<<" "<<char(to[i+2])<<" "<<s[i]<<" "<<nx[i+2]<<"!!\n";
				is[i]=is[i+1]=1,to[i]=to[i+2],nx[i]=nx[i+2];// 
			}
			// 
			else 
			{
				to[i]=s[i],nx[i]=i;
				if(to[i+1]!=s[i])ndf[i]=to[i+1];
				else ndf[i]=ndf[nx[i+1]];
			}
		}
	}
	l=xx,r=l-1;
	for(int i=1;i<=n;i++)if(!is[i])q[++r]=i;
	
	for(int i=1;i<=n;i++)
	{
		cout<<r-l+1<<" ";
		if(r-l+1<=10)
		{
			for(int j=l;j<=r;j++)cout<<s[q[j]];
			puts("");
		}
		else 
		{
			for(int j=l;j<l+5;j++)cout<<s[q[j]];
			cout<<"...";
			for(int j=r-1;j<=r;j++)cout<<s[q[j]];
			puts("");
		}
		if(!is[i])l++;
		else 
			is[i]=is[i+1]=0,q[--l]=i;
	}
	pc('1',1);
	return 0;
}