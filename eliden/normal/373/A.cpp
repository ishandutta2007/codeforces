#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 2e5;

int main()
{
	int k;
	scanf("%d",&k);
	int c[10];
	rep(i,0,10)
		c[i] = 0;
	rep(i,0,4)
	{
		string s;
		cin >> s;
		rep(i,0,4)
			if(s[i]!='.')
				c[s[i]-'0']++;
	}
	bool good = true;
	rep(i,0,10)
		if(c[i]>2*k)
			good = false;
	if(good)
		printf("YES\n");
	else
		printf("NO\n");
}