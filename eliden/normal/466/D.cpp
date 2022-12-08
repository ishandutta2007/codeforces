#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;
const ll modul = 1e9+7;
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n, h;
	cin >> n >> h;
	ll pos = 1;
	int avail=0,last=0, a;
	bool good=true;
	for(int i=0;i<=n && good;++i)
	{
		if(i==n)
			a = 0;
		else
			cin>>a, a = h-a;
		if(a==last+1)
			++avail;
		else if(a==last-1)
			pos*=avail, pos%=modul, --avail;
		else if(a==last)
			pos*=avail+1, pos%=modul;
		else
			good=false;
		last = a;
	}
	if(good)
		cout<<pos<<endl;
	else
		cout<<0<<endl;
	return 0;
}