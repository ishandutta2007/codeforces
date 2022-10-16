#include<bits/stdc++.h>
#define ll long long
#define dd long double
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int T;
long double v,a,b,c;
dd get(dd x)
{
	if(x<=v)return 2*x+(1000-x);//x1-x 
	return (get(x-v)+1000)*x/1000+(1000-x);
}
int tot=0;
dd dfs(dd a,dd b)
{
//	cout<<a<<' '<<b<<'\n';
	tot++;
	dd ans=0;
	if(a<=v)ans+=a*(1000+get(b+a/2))/1000;
	else ans+=a*(1000+dfs(a-v,b+v/2))/1000;
	if(b<=v)ans+=b*(1000+get(a+b/2))/1000;
	else ans+=b*(1000+dfs(a+v/2,b-v))/1000;
	ans+=(1000-a-b);
	return ans;
}
int main(){
	T=read();
	while(T--)
	{
		tot=0;
		cin>>a>>b>>c>>v;
//		scanf("%Lf%Lf%Lf%Lf",&a,&b,&c,&v);
		a*=1000;
		b*=1000;
		c*=1000;
		v*=1000;
		cout<<fixed<<setprecision(10)<<dfs(a,b)/1000<<'\n';
//		cout<<tot<<"\n";
	}
	return 0;
}