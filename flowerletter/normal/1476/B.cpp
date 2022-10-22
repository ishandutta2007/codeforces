#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
int a[1005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		for(int i=1;i<=n;i++) cin >> a[i];
		int ans=0,s=a[1];
		for(int i=2;i<=n;i++)
		{
			if(s*k<a[i]*100)
			{
				ans+=(a[i]*100-s*k)/k;
				s+=(a[i]*100-s*k)/k;
			}
			while(s*k<a[i]*100)
				++s,++ans;
			s+=a[i];
		}
		cout << ans << "\n";
	}
	return 0;
}