#include<bits/stdc++.h>
using namespace std;
int n,a[111111],oe[111111],curp,cur;
vector<int> v[5];
set<pair<int,int> > s;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	curp=n+1;
	for (int i=n;i>=1;i--)
	{
		if (a[i]==1)
		{
			s.insert(make_pair(curp-1,i));
			v[1].push_back(i);
			curp--;oe[i]=curp;
		}
		else if (a[i]==2)
		{
			if (v[1].empty())
			{
				printf("-1\n");
				return 0;
			}
			cur=v[1].back();
			oe[i]=oe[cur];
			s.insert(make_pair(oe[cur],i));
			v[1].pop_back();
			v[0].push_back(i);
		}
		else if (a[i]==3)
		{
			if (!v[1].size() && !v[0].size())
			{
				printf("-1\n");
				return 0;
			}
			curp--;oe[i]=curp;
			if (v[0].empty()) cur=v[1].back();
			else cur=v[0].back();
			s.insert(make_pair(curp,i));
			s.insert(make_pair(curp,cur));
			if (v[0].empty()) v[1].pop_back();
			else v[0].pop_back();
			v[0].push_back(i);
		}
	}
	printf("%d\n",(int)s.size());
	for (set<pair<int,int> >::iterator it=s.begin();it!=s.end();it++) 
	printf("%d %d\n",it->first,it->second);
	return 0;
}