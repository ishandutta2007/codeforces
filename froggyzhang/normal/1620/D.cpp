#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,a[N];
int calc(int x,int y){
	int t=0;
	for(int i=1;i<=n;++i){
		int mn=inf;
		for(int p=0;p<=x;++p){
			for(int q=0;q<=y;++q){
				int c=p+q*2;
				if(a[i]>=c&&(a[i]-c)%3==0)mn=min(mn,(a[i]-c)/3);
			}
		}
		t=max(t,mn);
	}
	t+=x+y;
	return t;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int ans=inf;
	for(int i=0;i<=2;++i){
		for(int j=0;j<=2;++j){
			ans=min(ans,calc(i,j));
		}	
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		Solve();
	}
	return 0;
}