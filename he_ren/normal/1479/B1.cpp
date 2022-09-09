#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans = 0, lst = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[i] == a[j]) ++j;
		if(j-i == 1){ ++ans; continue;}
		
		ans += 2;
		if(a[lst] == a[i])
		{
			bool ok = 0;
			for(int k=lst+1; k<i; ++k)
				if(a[k] != a[i] && a[k-1] != a[k+1])
				{
					ok = 1;
					break;
				}
			if(!ok) --ans;
		}
		lst = j-1;
	}
	
	printf("%d",ans);
	return 0;
}