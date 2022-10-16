#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,X,a[N];
void Solve(){
	cin>>n>>X;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int s=0,mn=a[1],mx=a[1];
	for(int i=2;i<=n;++i){
		int tmn=min(mn,a[i]),tmx=max(mx,a[i]);
		if(tmx-tmn<=X*2){
			mn=tmn,mx=tmx;
		}
		else{
			mn=mx=a[i],++s;
		}
	}
	cout<<s<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}