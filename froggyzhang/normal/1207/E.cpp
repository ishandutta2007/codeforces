#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void Solve(){
	int ans=0,x;
	cout<<"? ";
	for(int i=1;i<=100;++i){
		cout<<i<<" ";
	}
	cout<<endl;
	cin>>x;
	ans^=x&(((1<<7)-1)<<7);
	cout<<"? ";
	for(int i=0;i<100;++i){
		cout<<(i<<7)<<" ";	
	}
	cout<<endl;
	cin>>x;
	ans^=x&((1<<7)-1);
	cout<<"! "<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}