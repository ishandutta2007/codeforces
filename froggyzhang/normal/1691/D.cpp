#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=1e18;
int n,lg[N];
ll mx[N][21];
ll a[N],s[N];
inline ll Ask(int l,int r){
	int k=lg[r-l+1];
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
void init(ll *s,int n){
	for(int i=0;i<=n;++i){
		mx[i][0]=-s[i];
	}
	for(int i=2;i<=n+1;++i)lg[i]=lg[i>>1]+1;
	for(int j=1;j<=20;++j){
		for(int i=0;i+(1<<j)-1<=n;++i){
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
		}
	}
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	init(s,n);
	static int st[N],top;
	top=0;
	for(int i=1;i<=n;++i){
		while(top&&a[i]>=a[st[top]])--top;
		st[++top]=i;
		if(s[i-1]+Ask(st[top-1],i-1)>0){
			cout<<"NO\n";
			return;
		}
	}
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	init(s,n);
	top=0;
	for(int i=1;i<=n;++i){
		while(top&&a[i]>=a[st[top]])--top;
		st[++top]=i;
		if(s[i-1]+Ask(st[top-1],i-1)>0){
			cout<<"NO\n";
			return;
		}
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