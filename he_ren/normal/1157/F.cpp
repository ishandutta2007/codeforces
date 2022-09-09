#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];
bool tag[MAXN];

array<int,3> mx;
void upd_mx(int l,int r)
{
	for(int i=l,j=l;; i=j)
	{
		j = i+1;
		while(j<=r && !tag[j]) ++j;
		if(j > r)
		{
			mx = max(mx, {j - i, i, j - 1});
			return;
		}
		mx = max(mx, {j - i + 1, i, j});
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i)
		tag[i] = a[i] != a[i-1] && a[i] != a[i+1];
	
	for(int i=1,j=1; i<=n; i=j)
	{
		j = i+1;
		while(j<=n && a[j] <= a[j-1]+1) ++j;
		upd_mx(i, j-1);
	}
	
	int l = mx[1], r = mx[2];
	vector<int> ans;
	for(int i=l; i<=r; ++i)
		if(a[i] == a[i-1]) ans.push_back(a[i]);
	for(int i=a[r]; i>=a[l]; --i)
		ans.push_back(i);
	
	printf("%d\n",(int)ans.size());
	for(int x: ans) printf("%d ",x);
	return 0;
}