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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> p(n+1);
	vector<bool> ok(n+1,false);
	p[0] = -1;
	p[1] = 0;
	int j = 0;
	repeq(i,2,n)
	{
		while(j>=0 && s[j+1-1]!=s[i-1])
			j = p[j];
		j++;
		p[i] = j;
		if(i<n)
			ok[p[i]]=true;
	}
	while(j>0 && !ok[j])
		j = p[j];
	if(j>0)
		cout << s.substr(0,j) << endl;
	else
		cout << "Just a legend\n";
	return 0;
}