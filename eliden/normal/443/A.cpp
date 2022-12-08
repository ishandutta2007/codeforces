#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 2e5;

int main()
{
	string s;
	getline(cin,s);
	bool a[26];
	rep(i,0,26)
		a[i] = false;
	rep(i,0,s.size())
		if('a'<=s[i] && s[i]<='z')
			a[s[i]-'a']=true;
	int count=0;
	rep(i,0,26)
		if(a[i])
			count++;
	printf("%d\n",count);
}