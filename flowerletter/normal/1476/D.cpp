#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int qwq[300005],ans[300005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string a;
		cin >> a;
		a=' '+a;
		int now=0;
		for(int i=1;i<=n+1;i++) ans[i]=0;
		for(int i=2;i<=n;i+=2) if(a[i]=='L') a[i]='R';else a[i]='L';
		for(int i=n;i>=1;i--)
		{
			if(a[i]=='R') ++now;
			else now=0;
			if(i&1) ans[i]+=now;
		}
		for(int i=1;i<=n;i++) if(a[i]=='L') a[i]='R';else a[i]='L';
		now=0;
		for(int i=1;i<=n;i++)
		{
			if(i&1) ans[i]+=now;
			if(a[i]=='L') ++now;
			else now=0;
		}
		if(n+1&1)ans[n+1]+=now;
		now=0;
		now=0;
		for(int i=1;i<=n;i++) if(a[i]=='L') a[i]='R';else a[i]='L';
		for(int i=1;i<=n;i++)
		{
			if(i%2==0) ans[i]+=now;
			if(a[i]=='L') ++now;
			else now=0;
		}
		if(n%2==1) ans[n+1]=now;
		for(int i=1;i<=n;i++) if(a[i]=='L') a[i]='R';else a[i]='L';
		now=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]=='R') ++now;
			else now=0;
			if(i%2==0) ans[i]+=now;
		}
		for(int i=1;i<=n+1;i++)
			cout << ans[i]+1 << " ";
		puts("");
	}
	return 0;
}