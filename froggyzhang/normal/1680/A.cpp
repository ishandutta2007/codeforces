#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int l1,r1,l2,r2;
void Solve(){
	cin>>l1>>r1>>l2>>r2;
	int l=max(l1,l2),r=min(r1,r2);
	if(l<=r){
		cout<<l<<'\n';
	}
	else{
		cout<<l1+l2<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}