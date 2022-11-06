#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int s=0;
		for(int i=1;i<=n;++i){
			int x;
			cin>>x;
			s+=x;
		}
		int ans=max(1,s-n);
		if(s==n)ans=0;
		cout<<ans<<endl;
	}
}