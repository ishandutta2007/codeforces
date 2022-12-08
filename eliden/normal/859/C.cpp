#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;
const int SZ=1000;
ll v[SZ];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n)
		cin >> v[i];
	ll tot=0, last=0;
	for(int i=n-1;i>=0;--i)
	{
		last = max(last,v[i]+tot-last);
		tot+=v[i];
	}
	cout << tot-last << " " << last << endl;
}