#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m;
int n,pl[10],a[100005];
char str[100005];
set<ll> dfs(int l,int r){
	set<ll> ret;
	if(l==r){
		ret.insert(1<<str[l]-'a');
		return ret;
	}
	for(int i=l;i<r;i++){
		set<ll> a=dfs(l,i),b=dfs(i+1,r);
		for(ll j:a)for(ll k:b)ret.insert(-j+k);
	}
	return ret;
}
ll ABS(ll x){
	return x<0?-x:x;
}
int main() {
	cin>>n>>m>>str+1;
	for(int i=1;i<=n;i++){
		a[i]=str[i]-'a';
	}
	m-=1<<a[n];
	m+=1<<a[n-1];
	sort(a+1,a+n-1);
	for(int i=n-2;i>=1;i--){
		if(ABS(m-(1<<a[i]))>ABS(m+(1<<a[i])))m+=(1<<a[i]);
		else m-=(1<<a[i]);
	}
	if(!m)cout<<"yes";
	else cout<<"no";
	return 0;
}