#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 100;

int main()
{
	int n;
	bool a[sz][sz];
	scanf("%d",&n);
	rep(i,0,n)
	{
		string s;
		cin >> s;
		rep(j,0,s.size())
			a[i][j] = s[j]=='#';
	}
	rep(i,0,n-2)
	{
		rep(j,1,n-1)
			if(a[i][j]&&a[i+1][j-1]&&a[i+1][j]&&a[i+1][j+1]&&a[i+2][j])
				a[i][j]=a[i+1][j-1]=a[i+1][j]=a[i+1][j+1]=a[i+2][j]=false;
	}
	bool good = true;
	rep(i,0,n)
	{
		rep(j,0,n)
			if(a[i][j])
				good = false;
	}
	if(good)
		printf("YES\n");
	else
		printf("NO\n");
}