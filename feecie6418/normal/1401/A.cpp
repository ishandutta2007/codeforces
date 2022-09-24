#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		if(n>=k&&(n-k)%2==0)cout<<0<<endl;
		else if(n<k)cout<<k-n<<endl;
		else cout<<1<<endl;
	}
	return 0;
}