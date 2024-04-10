#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

struct pr{
	int id,d;
}p[maxn];

int n;
vector<pair<int,int> > Ans;
deque<int> D;

inline bool cmpd(const pr&a,const pr&b){return a.d>b.d;}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("inp.in","r",stdin);
	freopen("oup.out","w",stdout);
	#endif

	int i;

	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&p[i].d),p[i].id=i;

	sort(p,p+n,cmpd);
	for(i=0;i<n-1;i++) Ans.push_back(make_pair(p[i].id<<1,p[i+1].id<<1)),D.push_back(p[i].id<<1);
	D.push_back(p[n-1].id<<1);

	for(i=0;i<n;i++)
	{
		Ans.push_back(make_pair(D[p[i].d-1],p[i].id<<1|1));
		if(p[i].d-1 == (int)D.size()-1) D.push_back(p[i].id<<1|1);
		D.pop_front();
	}

	for(i=0;i<(int)Ans.size();i++) printf("%d %d\n",Ans[i].first+1,Ans[i].second+1);
	
	return 0;
}