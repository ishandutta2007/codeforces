#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=4e18;
int n,q,x[300005],w[300005],st[300005],top;
struct Point{
	int r,id;
	ll val;
};
vector<Point> a[300005];
ll c[300005],ans[300005];
void U(int x,ll y){
	while(x<=n)c[x]=min(c[x],y),x+=x&-x;
}
ll Q(int x){
	ll r=inf;
	while(x)r=min(r,c[x]),x-=x&-x;
	return r;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>w[i],c[i]=inf;
		while(top&&w[st[top]]>=w[i]){
			a[st[top]].push_back({i,0,1ll*(x[i]-x[st[top]])*(w[i]+w[st[top]])});
			top--;
		}
		if(top)a[st[top]].push_back({i,0,1ll*(x[i]-x[st[top]])*(w[i]+w[st[top]])});
		st[++top]=i;
	}
	for(int i=1,l,r;i<=q;i++)cin>>l>>r,a[l].push_back({r,i,0});
	for(int i=n;i>=1;i--){
		for(auto j:a[i])if(!j.id)U(j.r,j.val);
		for(auto j:a[i])if(j.id)ans[j.id]=Q(j.r);
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
}