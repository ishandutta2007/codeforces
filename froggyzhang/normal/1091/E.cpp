#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
int n,a[N];
ll s[N],l,r;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	r=n;
	for(int k=1,j=0;k<=n;++k){
		while(j<n&&a[j+1]<k)++j;
		ll t=s[n]-s[n-k]-1LL*k*(k-1)-s[min(n-k,j)]-1LL*k*(n-k-min(n-k,j));
		l=max(l,t);
		r=min(r,-t+a[n-k+1]+min(k,a[n-k+1]));	
	}
	if(l>r){
		cout<<-1<<'\n';
		return 0;
	}
	for(int i=l;i<=r;++i){
		if(!((s[n]+i)&1))cout<<i<<' ';
	}
	return 0;
}