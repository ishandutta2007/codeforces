#include<bits/stdc++.h>
using namespace std;
int n,a[55],cnt[55],mn=1e9;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++,mn=min(mn,a[i]);
	if(cnt[mn]>n/2)puts("Bob");
	else puts("Alice");
	return 0;
}