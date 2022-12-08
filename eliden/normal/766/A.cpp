#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e6;

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	if(s1==s2)
		printf("-1\n");
	else
		printf("%d\n",max(s1.size(),s2.size()));
}