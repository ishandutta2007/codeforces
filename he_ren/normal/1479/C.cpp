#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

vector< pair<pii,int> > ans;
inline void push_ans(int u,int v,int w){ ans.push_back(make_pair(make_pair(u,v),w));}

int main(void)
{
	int l,r;
	scanf("%d%d",&l,&r);
	
	for(int i=2; i<=21; ++i)
	{
		push_ans(1, i, 1);
		for(int j=i+1; j<=21; ++j)
			push_ans(i, j, bbit(i-2));
	}
	
	r -= l;
	for(int i=0; i<=19; ++i)
		if(bdig(r, i))
		{
			int rem = bbit(i+1) - 1;
			push_ans(i+2, 22, l + ((r | rem) ^ rem));
		}
	push_ans(1, 22, l);
	
	printf("YES\n22 %d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second);
	return 0;
}