#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define repeq(a,b,c) for(int a=b;a<=c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
typedef long long ll;
const int SZ = 1e5;
bool a[SZ], b[SZ];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n)
	{
		int x;
		cin >> x;
		a[i] = x==1;
	}
	bool found = false;
	int m = n;
	for(int p=3;p<=m && !found;++p)
		if(m%p==0)
		{
			while(m%p==0)
				m/=p;
			int k = n/p;
			rep(i,0,k)
				b[i] = true;
			rep(i,0,n)
				if(!a[i])
					b[i%k]=false;
			rep(i,0,k)
				if(b[i])
					found = true;
		}
	if(found)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}