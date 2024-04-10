#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,a[N];
char s[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>(s+1);
	vector<int> A,B;
	for(int i=1;i<=n;++i){
		if(s[i]=='R')A.push_back(a[i]);
		else B.push_back(a[i]);
	}
	sort(A.begin(),A.end(),greater<int>());
	sort(B.begin(),B.end());
	int now=n;
	for(auto x:A){
		if(x>now){
			cout<<"NO\n";
			return;
		}
		--now;
	}
	now=1;
	for(auto x:B){
		if(x<now){
			cout<<"NO\n";
			return;
		}
		++now;
	}
	cout<<"YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}