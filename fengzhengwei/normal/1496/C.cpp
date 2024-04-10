#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
double x[xx];
double y[xx];
signed main(){
	int T=read();
	while(T--)
	{
		int n=read();
		int s1=0,s2=0;
		for(int i=1;i<=n+n;i++)
		{
			int a,b;
			a=read();
			b=read();
			if(a==0)y[++s2]=abs(b);
			if(b==0)x[++s1]=abs(a);
		}
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		double ans=0;
		for(int i=n;i>=1;i--)ans+=sqrt(x[i]*x[i]+y[i]*y[i]);
		cout<<fixed<<setprecision(9)<<ans<<"\n";
	}
	return 0;
}