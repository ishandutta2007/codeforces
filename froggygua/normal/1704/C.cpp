#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,a[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	int jb=0;
	vector<int> A;
	for(int i=1;i<m;++i){
		A.push_back(a[i+1]-a[i]-1);
	}
	A.push_back(n-a[m]+a[1]-1);
	sort(A.begin(),A.end(),greater<int>());
	int t=1;
	for(auto x:A){
		if(x==t){
			++jb;
			break;
		}
		if(t>x)break;
		jb+=x-t;
		t+=4;
	}
	cout<<n-jb<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}