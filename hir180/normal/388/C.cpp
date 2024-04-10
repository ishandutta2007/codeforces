#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
using namespace std;
#define pb push_back
int main()
{
	int n; scanf("%d",&n);
	int reta=0,retb=0;
	multiset<int,greater<int> >se;
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		vector<int>vec;
		for(int j=0;j<x;j++)
		{
			int a;  scanf("%d",&a);
			vec.pb(a);
		}
		for(int i=0;i<x/2;i++) reta+=vec[i];
		for(int i=x-x/2;i<x;i++) retb+=vec[i];
		if(x/2!=x-x/2) se.insert(vec[x/2]);
	}
	int cnt=0;
	for(multiset<int,greater<int> >::iterator it=se.begin();it!=se.end();++it,++cnt)
	{
		if(cnt%2==0) reta+=*it;
		else retb+=*it;
	}
	printf("%d %d\n",reta,retb);
}