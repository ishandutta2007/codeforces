#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,cnt[2]={0};
		cin>>n;
		for(int i=1,x;i<=n*2;i++)cin>>x,cnt[x%2]++;
		if(cnt[0]==n)puts("Yes");
		else puts("No");
	}
	return 0;
}