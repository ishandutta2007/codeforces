#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 5e3 + 5;

string s;

void solve(void)
{
	int n;
	cin>>n>>s;
	
	int ans=1;
	string anss=s;
	for(int i=2; i<=n; ++i)
	{
		string t = s.substr(0,i-1);
		if((n-i+1)&1) reverse(t.begin(),t.end());
		t = s.substr(i-1,s.size()) + t;
		if(t<anss)
			ans=i, anss=t;
	}
	cout<<anss<<endl<<ans<<endl;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}