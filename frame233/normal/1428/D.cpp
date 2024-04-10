// Author -- xyr2005
#include<bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)x.size())
#define pb push_back
const int N=100005;
int a[N],p[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	std::vector<std::pair<int,int>> ans;
	int cnt=0;
	std::vector<int> v1,v2;
	for(int i=n;i>=1;--i)
	{
		if(a[i]==1)
		{
			ans.pb({i,p[i]=++cnt});
			v1.pb(i);
		}
		else if(a[i]==2)
		{
			if(v1.empty()) return puts("-1"),0;
			int x=v1.back();v1.pop_back();
			ans.pb({i,p[i]=p[x]});
			v2.pb(i);
		}
		else if(a[i]==3)
		{
			int x=-114514;
			if(!v2.empty()){x=v2.back();v2.pop_back();}
			else if(!v1.empty()){x=v1.back();v1.pop_back();}
			if(x<0) return puts("-1"),0;
			p[i]=++cnt,ans.pb({i,cnt}),ans.pb({x,cnt});
			v2.pb(i);
		}
	}
	printf("%d\n",SZ(ans));
	for(auto it:ans) printf("%d %d\n",n-it.second+1,it.first);
	return 0;
}