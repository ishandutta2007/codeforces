#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pr;
ll din[100005],dout[100005];
int n,m,s=0,top;
struct Ans{
	int l,r;
	ll x;
}ans[500005];
pr st[500005];
ll sgn(ll x){
	return x/abs(x);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		din[y]+=z,dout[x]+=z;
	}
	for(int i=1;i<=n;i++){
		ll w=din[i]-dout[i];
		if(!w)continue;
		while(top&&sgn(st[top].second)!=sgn(w)){
			ll t=min(abs(st[top].second),abs(w));
			if(w<0)w+=t,st[top].second-=t,ans[++s]={i,st[top].first,t};
			else w-=t,st[top].second+=t,ans[++s]={st[top].first,i,t};
			if(!st[top].second)top--;
			if(!w)break;
		}
		if(w)st[++top]=pr(i,w);
	}
	cout<<s<<'\n';
	for(int i=1;i<=s;i++)cout<<ans[i].l<<' '<<ans[i].r<<' '<<ans[i].x<<'\n';
}