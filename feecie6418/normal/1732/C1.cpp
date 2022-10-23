#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
typedef long long ll;
int n,q,a[100005],nxt[100005],pre[100005];
ll sum[100005],xa[100005];
void Solve(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<=n+1;i++)nxt[i]=pre[i]=a[i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i],xa[i]=(xa[i-1]^a[i]);
		if(a[i-1])pre[i]=i-1;
		else pre[i]=pre[i-1];
	}
	for(int i=n;i;i--){
		if(a[i+1])nxt[i]=i+1;
		else nxt[i]=nxt[i+1];
	}
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		ll ans=sum[r]-sum[l-1]-(xa[r]^xa[l-1]);
		if(ans==0){
			cout<<l<<' '<<l<<'\n';
			continue;
		}
		int mn=r-l,P=l,Q=r;
		vector<int> tl,tr;
		for(int o=l,cnt=0;o<=r&&o&&cnt<40;o=nxt[o],cnt++)tl.push_back(o);
		for(int o=r,cnt=0;o>=l&&o&&cnt<40;o=pre[o],cnt++)tr.push_back(o);
		for(int p:tl){
			for(int q:tr){
				if(p<=q&&sum[q]-sum[p-1]-(xa[q]^xa[p-1])==ans){
					if(q-p<mn)mn=q-p,P=p,Q=q;
				}
			}
		}
		cout<<P<<' '<<Q<<'\n';
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve(); 
}