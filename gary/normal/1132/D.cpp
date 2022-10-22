#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=2e5+100000;
ll	ans=-1,need[INF],a[INF];
int n,k,b[INF],cnt[INF];
bool judge(ll mid){
	for(int i=1;i<k;i++){
		cnt[i]=0;
	}
	ll tot=k-1;
	for(int i=1;i<=n;i++){
		if(!b[i]) continue;
		ll tmp=a[i];
		while(tmp<need[i]){
			cnt[tmp/b[i]+1]++;
			tmp+=mid;
			if(!tot) return false;
			tot--;	
		}
	}
	for(int i=1;i<k;i++){
		cnt[i]+=cnt[i-1];
		if(cnt[i]>i) return false;
	}
	return true;
}
void solve(){
	ll l=0,r=2e12,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(judge(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	} 
}
void print(){
	cout<<ans<<endl;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
			scanf("%d",&b[i]);need[i]= (ll)(k-1)*b[i];
		}
	solve();
	print();
	return 0;
}