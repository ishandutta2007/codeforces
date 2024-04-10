#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXA = 5e2 + 5;
typedef bitset<512> Data;

struct BIT
{
	Data tree[MAXA];
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,const Data &k)
	{
		x += 2;
		while(x<MAXA)
			tree[x] |= k,
			x += lowbit(x);
	}
	inline Data query(int x)
	{
		x += 2;
		Data res;
		while(x)
			res |= tree[x],
			x ^= lowbit(x);
		return res;
	}
}tree;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	tree.update(-1, Data(1));
	for(int i=1; i<=n; ++i)
	{
		Data res = tree.query(a[i] - 1);
		Data f;
		for(int j=0; j<512; ++j) if(res[j])
			f[j ^ a[i]] = 1;
		tree.update(a[i], f);
	}
	
	Data ans = tree.query(5e2);
	vector<int> vec;
	for(int i=0; i<512; ++i) if(ans[i])
		vec.push_back(i);
	
	printf("%d\n",(int)vec.size());
	for(int x: vec) printf("%d ",x);
	return 0;
}