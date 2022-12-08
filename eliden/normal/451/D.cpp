#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	vector<int> c(4,0);
	ll te = 0, to = 0;
	int n = s.length();
	rep(i,0,n)
	{
		int j = s[i]-'a';
		int d = 2*(i%2);
		++c[j+d];
		to+=c[j+d];
		te+=c[j+2-d];
	}
	cout<<te<<" "<<to<<endl;		
}