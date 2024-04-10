#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],c[N];
set<int>s,t;
vector<int>v;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s.clear(),v.clear();
	for(int i=0;i<=n+1;i++)
	{
		c[i]=0;
		s.insert(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!c[a[i]])
			s.erase(a[i]);
		c[a[i]]++;
	}
	int p=1;
	while(p<=n)
	{
		int z=*s.begin();
		if(!z)
		{
			for(int i=p;i<=n;i++)
				v.push_back(0);
			break;
		}
		t.clear();
		for(int i=0;i<z;i++)
			t.insert(i);
		while(t.size())
		{
			if(t.count(a[p]))
				t.erase(a[p]);
			c[a[p]]--;
			if(!c[a[p]])
				s.insert(a[p]);
			p++;
		}
		v.push_back(z);
	}
	printf("%d\n",v.size());
	for(auto i:v)
		printf("%d ",i);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}