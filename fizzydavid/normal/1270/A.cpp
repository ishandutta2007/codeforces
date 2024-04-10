//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		vector<int> v;
		for (int i=0; i<n; i++)
		{
			int val;
			scanf("%d", &val);
			v.PB(val);
		}
		if (max_element(v.begin(), v.end())-v.begin()<x) puts("YES"); else puts("NO");
	}
	return 0;
}