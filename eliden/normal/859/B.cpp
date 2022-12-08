#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	ll sn = sqrt(n);
	if(sn*sn==n)
		cout << 4*sn << endl;
	else if(sn*(sn+1)>=n)
	{
		cout << 4*sn+2<<endl;
	}
	else
	{
		cout << 4*sn+4<<endl;
	}
}