#include<bits/stdc++.h>
using namespace std;
int n;
long long ans1,ans2;
int main() {
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(x%2==0)ans1+=x/2,ans2+=x/2;
		else if(i&1)ans1+=x/2,ans2+=x/2+1;
		else ans1+=x/2+1,ans2+=x/2;
	}
	cout<<min(ans1,ans2);
	return 0;
}