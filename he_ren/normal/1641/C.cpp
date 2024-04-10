#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	
	set<int> t;
	for(int i=0; i<=n+1; ++i) t.insert(i);
	
	map<int,int> sufmn;
	while(Q--)
	{
		int type;
		scanf("%d",&type);
		if(type == 0)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			if(x == 0)
			{
				for(auto it = t.lower_bound(l); *it <= r;)
					t.erase(it++);
			}
			else
			{
				auto it = sufmn.lower_bound(l);
				if(it != sufmn.end() && it -> second <= r) continue;
				while(it != sufmn.begin() && prev(it) -> second >= r)
					sufmn.erase(prev(it));
				sufmn[l] = r;
			}
		}
		else
		{
			int x;
			scanf("%d",&x);
			auto it = t.lower_bound(x);
			if(*it != x)
			{
				printf("NO\n");
				continue;
			}
			int l = *prev(it) + 1, r = *next(it) - 1;
			
			auto it2 = sufmn.lower_bound(l);
			if(it2 != sufmn.end() && it2 -> second <= r)
			{
				printf("YES\n");
			}
			else
			{
				printf("N/A\n");
			}
		}
	}
	return 0;
}