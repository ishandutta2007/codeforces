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
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
const int xx=85;
int f[xx][xx*xx][xx+xx],a[xx],n,s[xx],tt;
void ad(int &a,int b){a<b?a=b:0;}
int ans[xx*xx];
int main(){
	n=read();
	vector<int>v;
	for(int i=1;i<=n;i++)a[i]=read(),(a[i]?v.push_back(i):void());
	tt=v.size();
	for(int i=1;i<=tt;i++)s[i]=v[i-1]-i;//0 
	memset(f,-0x3f,sizeof(f));
	s[tt+1]=n-v.size();
	f[0][0][0]=0;
	for(int i=0;i<=tt;i++)//tt+1 
	{
		for(int j=0;j<=n*(n-1)/2;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(f[i][j][k]<0)continue;
				for(int g=0;g<=s[i+1]-k;g++)// 
					ad(f[i+1][j+g][s[i+1]-g],f[i][j][k]+k*(s[i+1]-g-k));
				for(int g=max(0,k-s[i+1]);g<=n;g++)// 
					ad(f[i+1][j+g][s[i+1]+g],f[i][j][k]+(s[i+1]+g-k)*k);
//				cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<" "<<s[i+2]<<" "<<s[i+1]<<"\n";
			}
		}
	}
	for(int i=0;i<=n*(n-1)/2;i++)
		ans[i]=f[tt+1][i][s[tt+1]],(i&&(ans[i]=max(ans[i],ans[i-1]))),cout<<ans[i]<<" ";
	return 0;
}