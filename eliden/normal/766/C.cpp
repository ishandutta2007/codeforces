#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 2e3;
const int M = 1000000007;
int main()
{
	int n, a[26];
	string s;
	scanf("%d",&n);
	cin >> s;
	rep(i,0,26)
		scanf("%d",&a[i]);

	long long num[sz];
	int dpmin[sz];
	num[0] = 1;
	dpmin[0] = 0;
	int count[26];
	int longest = 0;
	rep(i,1,n+1)
	{
		bool good = true;
		num[i] = 0;
		dpmin[i] = -1;
		int len = 0, bound = n;
		for(int j=i-1;good && j>=0;j--)
		{
			len++;
			int c = s[j]-'a';
			if(a[c]<bound)
				bound = a[c];
			if(len>bound)
				good = false;
			else
			{
				if(len>longest)
					longest = len;
				num[i]=(num[i]+num[j])%M;
				if(dpmin[i]<0 || dpmin[j]+1<dpmin[i])
					dpmin[i] = dpmin[j]+1;
			}

		}
	}
	printf("%lld\n%d\n%d\n",num[n],longest,dpmin[n]);
}