#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct T{
	ll id,dlt;
	bool operator <(const T t) const {
		return dlt>t.dlt;
	}
};
priority_queue<T> q;
int n,K,a[100005],f[100005];
ll ans=0;
ll F(ll x,ll k){
	ll l=x/k;
	return l*l*(k-x%k)+(l+1)*(l+1)*(x%k);
}
int main(){
	scanf("%d%d",&n,&K),K-=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),f[i]=1,ans+=1ll*a[i]*a[i];
		if(a[i]>1)q.push({i,F(a[i],2)-F(a[i],1)});
	}
	while(K--){
		T x=q.top();
		int i=x.id;
		q.pop();
		ans+=x.dlt,f[i]++;
		if(a[i]>f[i])q.push({i,F(a[i],f[i]+1)-F(a[i],f[i])});
	}
	cout<<ans;
	return 0;
}