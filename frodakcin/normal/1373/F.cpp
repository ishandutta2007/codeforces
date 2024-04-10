#include <cstdio>
#include <algorithm>

using ll = long long;
const int MN = 1e6+10;
const int MX = 1e9+10;
ll s;
int T, N, a[MN*2], b[MN*2];
void fail(){printf("NO\n");}
void solve()
{
	scanf("%d", &N);
	s=0;
	for(int i=0;i<N;++i)
		scanf("%d", a+i), s+=a[i], a[i+N]=a[i];
	for(int i=0;i<N;++i)
		scanf("%d", b+i), s-=b[i], b[i+N]=b[i];
	if(s>0) return fail();
	ll d=b[0];
	for(int i=1;i<N*2;++i)
	{
		if((d += b[i]-a[i])<0) return fail();
		d = std::min(d, (ll)b[i]);
	}
	printf("YES\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}