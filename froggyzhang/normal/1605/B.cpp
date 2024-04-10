#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
int n,a[N];
char s[N];
void Solve(){
	cin>>n;
	int mx=0,mn=n+1;
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'0';
		if(!a[i])mx=max(mx,i);
		else mn=min(mn,i);
	}
	if(mx<mn){
		cout<<0<<'\n';
		return;	
	}
	cout<<1<<'\n';
	vector<int> _1,_0;
	int i=1,j=n;
	while(i<=j){
		while(i<=n&&!a[i])++i;
		while(j>=1&&a[j])--j;
		if(i>j)break;
		_1.push_back(i);
		_0.push_back(j);
		++i,--j;	
	}
	cout<<_0.size()+_1.size()<<'\n';
	for(auto x:_1)cout<<x<<' ';
	reverse(_0.begin(),_0.end());
	for(auto x:_0)cout<<x<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}