#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif

const int N=111;
int a[N],d[N];
int n;
void solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>d[i];
	a[1]=d[1];
	for(int j=2;j<=n;++j) {
		if(!d[j]){
			a[j]=a[j-1];
		}else{
			int x=a[j-1]+d[j];
			int y=a[j-1]-d[j];
			if(y>=0){
				cout<<"-1\n";
				return;
			}
			a[j]=x;
		}
	}
	for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}