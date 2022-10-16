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
ll p,k;
vector<ll>ans;
vector<ll>res;
int main(){
	cin>>p>>k;
//	if(p<k)
//	{
//		cout<<1<<"\n";
//		cout<<p<<"\n";
//		exit(0);
//	}
	ll rem=p;
//	cout<<rem<<"!!\n";
	while(rem>=k||rem<0)
	{
		if(rem>=k)
		{
			ans.push_back(-(rem/k));
			rem=-(rem/k);
		}
		else 
		{
			ans.push_back((-rem+k-1)/k);
			rem=(-rem+k-1)/k;
		}
	}
	res.resize(ans.size()+1);
	for(int i=0;i<ans.size();i++)
		res[i+1]+=ans[i],res[i]+=ans[i]*k;
	res[0]+=p;
	cout<<res.size()<<"\n";
	for(auto it:res)cout<<it<<" ";puts("");
	pc('1',1);
	return 0;
}