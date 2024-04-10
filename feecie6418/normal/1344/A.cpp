#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		map<int,int> mp;
		bool f=0;
		for(int i=0,x;i<n;i++){
			cin>>x;
			int t=(i+x)%n;
			t=(t%n+n)%n;
			if(mp[t])f=1;
			mp[t]=1;
		}
		if(!f)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}