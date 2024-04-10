#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		long long sum=0;
		cin>>n;
		for(int i=0;i<n;++i){
			int x;
			cin>>x;
			sum+=x;
		}
		sum%=n;
		cout<<sum*(n-sum)<<"\n";
	}
}