#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXD = 45 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

ll t[MAXD],s[MAXD];

int main(void)
{
	int n,d;
	ll m;
	cin>>n>>d>>m;
	for(int i=1; i<=d; ++i) cin>>t[i];
	
	sort(t+1,t+d+1);
	for(int i=1; i<=d; ++i) s[i] = s[i-1]+t[i];
	
	int ans=0;
	for(int i=0; i<=n; ++i)
	{
		if(s[d]*i > m) break;
		
		ll tmp = m-s[d]*i;
		int res=0;
		for(int j=0; j<d; ++j)
		{
			if(s[j]*(n-i) > tmp) break;
			for(int k=0; k<=n-i; ++k)
			{
				if(s[j]*(n-i) + t[j+1]*k <= tmp)
					chk_max(res, j*(n-i)+k);
			}
		}
		chk_max(ans, res+i*(d+1));
	}
	printf("%d",ans);
	return 0;
}