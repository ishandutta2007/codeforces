//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;

typedef long double ld;
const ld pi=acos(-1);
ld ans=0;

ll ax,ay,ar,bx,by,br;
void calc()
{
	ll sqrd=(ax-bx)*(ax-bx)+(ay-by)*(ay-by);
	ld d=sqrt((ld)sqrd);
	ld a=(sqrd+ar*ar-br*br)/d/2;
	ld x=(sqrd+ar*ar-br*br)/(ld)sqrd/2;
	ld th=acos(a/ar)*2;
	ans+=ar*ar*(th-sin(th))/2;
}

int main()
{
	cin>>ax>>ay>>ar;
	cin>>bx>>by>>br;
	ll d2=(ax-bx)*(ax-bx)+(ay-by)*(ay-by);
	ll ar2=ar*ar;
	ll br2=br*br;
	if(d2>=(ar+br)*(ar+br))
	{
		puts("0");
		return 0;
	}
	if(d2<=(ar-br)*(ar-br))
	{
		ll r=min(ar,br);
		cout<<fixed<<setprecision(20)<<r*r*pi<<endl;
		return 0;
	}
	calc();
	swap(ax,bx);
	swap(ay,by);
	swap(ar,br);
	calc();
	cout<<fixed<<setprecision(20)<<ans<<endl;
	return 0;
}