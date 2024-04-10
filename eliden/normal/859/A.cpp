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
	int n;
	cin >> n;
	int m=0;
	rep(i,0,n)
	{
		int x;
		cin >> x;
		if(x>m)
			m=x;
	}
	if(m>25)
		cout << m-25<<endl;
	else
		cout << "0\n";
}