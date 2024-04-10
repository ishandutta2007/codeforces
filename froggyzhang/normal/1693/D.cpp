#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],ans[N];
void calc(int S){
	int x=0,y=n+1;
	for(int i=S;i<=n;++i){
		if(a[i]<x&&a[i]>y){
			ans[S]=i-1;
			return;
		}
		if(a[i]<x)y=min(y,a[i]);
		else if(a[i]>y)x=max(x,a[i]);
		else if(a[i+1]>a[i])x=max(x,a[i]);
		else y=min(y,a[i]);
	}
	ans[S]=n;
}
void Solve(int L,int R){
	if(L+1>=R)return;
	if(ans[L]==ans[R]){
		for(int i=L+1;i<R;++i){
			ans[i]=ans[L];
		}
		return;
	}
	int mid=(L+R)>>1;
	calc(mid);
	Solve(L,mid);
	Solve(mid,R);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	calc(1),calc(n);
	Solve(1,n);
	ll tot=0;
	for(int i=1;i<=n;++i){
		tot+=ans[i]-i+1;
	}
	cout<<tot<<'\n';
	return 0; 
}