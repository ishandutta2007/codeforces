#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const double eps=1e-12;
double a,b,c,v;

double dfs(double a,double b,double c)
{
//	cout<<a<<' '<<b<<' '<<c<<endl; 
	if (a<eps&&b<eps)return 1;
	if (a<eps)return 1+b*dfs(a,b-v,c);
	if (b<eps)return 1+a*dfs(a-v,b,c);
	return 1+a*(a<=v?dfs(0,b+a/2,c+a/2):dfs(a-v,b+v/2,c+v/2))+
	b*(b<=v?dfs(a+b/2,0,c+b/2):dfs(a+v/2,b-v,c+v/2));
}

signed main()
{
	WT
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&v);//t.clear();
		double ans=dfs(a,b,c);
		printf("%.12lf\n",ans);
	}
	return 0;
}