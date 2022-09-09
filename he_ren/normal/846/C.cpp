#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define mp make_pair
#define fir first
#define sec second
const int MAXN = 5e3 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void chk_max(pli &a,pli b){ if(a<b) a=b;}

ll a[MAXN],s[MAXN];

pli chk(int l,int r)
{
	pli res = mp(-linf,-1);
	for(int i=l; i<=r; ++i)
		chk_max(res, mp( (s[i]-s[l])-(s[r]-s[i]), i ));
	return res;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) cin>>a[i];
	
	for(int i=1; i<=n; ++i) s[i] = s[i-1]+a[i];
	
	int l,mid,r;
	ll ans=-linf;
	for(int i=0; i<=n; ++i)
	{
		pli res1=chk(0,i), res2=chk(i,n);
		if(res1.fir + res2.fir > ans)
		{
			ans = res1.fir + res2.fir;
			l = res1.sec;
			mid = i;
			r = res2.sec;
		}
	}
	printf("%d %d %d",l,mid,r);
	return 0;
}