#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int inf = 0x3f3f3f3f;

int a[MAXN];
int f[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	stack<pii> inc, dec;
	inc.push(make_pair(1, inf));
	dec.push(make_pair(1, inf));
	f[1] = 0;
	
	for(int i=2; i<=n; ++i)
	{
		f[i] = f[i-1] + 1;
		
		while(!inc.empty() && a[inc.top().first] >= a[i])
		{
			int k = inc.top().first;
			if(a[k] > a[i])
				f[i] = min(f[i], inc.top().second + 1);
			inc.pop();
		}
		if(inc.empty()) inc.push(make_pair(i, inf));
		else inc.push(make_pair(i, f[inc.top().first]));
		
		while(!dec.empty() && a[dec.top().first] <= a[i])
		{
			int k = dec.top().first;
			if(a[k] < a[i])
				f[i] = min(f[i], dec.top().second + 1);
			dec.pop();
		}
		if(dec.empty()) dec.push(make_pair(i, inf));
		else dec.push(make_pair(i, f[dec.top().first]));
	}
	
	printf("%d",f[n]);
	return 0;
}