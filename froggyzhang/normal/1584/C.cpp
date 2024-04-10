#include<bits/stdc++.h>
using namespace std;
#define N 123
typedef long long ll;
int n,a[N],b[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		if(!(a[i]==b[i]||a[i]+1==b[i])){
			cout<<"No\n";
			return;
		}	
	}	
	cout<<"Yes\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}