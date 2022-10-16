#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,bmn[1000005],bmx[1000005];
ll a[1000005],sum[2][105],s[1000005],mx[1000005],mn[1000005],ans=0;
struct Triple{
	int id,x,dlt;
};
vector<Triple> q[1000005];
void Solve(int l,int r){
	if(l==r)return ans++,void();
	int mid=(l+r)/2;
	mn[mid]=mx[mid]=a[mid];
	for(int i=mid-1;i>=l;i--){
		mn[i]=min(a[i],mn[i+1]);
		mx[i]=max(a[i],mx[i+1]);
	}
	mn[mid+1]=mx[mid+1]=a[mid+1];
	for(int i=mid+2;i<=r;i++){
		mn[i]=min(a[i],mn[i-1]);
		mx[i]=max(a[i],mx[i-1]);
	}
	for(int i=r;i>=l;i--)bmx[i]=__builtin_popcountll(mx[i]),bmn[i]=__builtin_popcountll(mn[i]);
	for(int i=r;i>=mid;i--)s[i]=s[i+1]+(bmn[i]==bmx[i]);
	for(int i=mid,j=mid,k=mid;i>=l;i--){
		while(j<r&&mx[j+1]<=mx[i])j++;
		while(k<r&&mn[k+1]>=mn[i])k++;
		ans+=min(j-mid,k-mid)*(bmn[i]==bmx[i]);
		ans+=s[max(j+1,k+1)];
		if(j<k){
			q[j].push_back({1,bmn[i],-1});
			q[k].push_back({1,bmn[i],1});
		}
		if(k<j){
			q[k].push_back({0,bmx[i],-1});
			q[j].push_back({0,bmx[i],1});
		}
	}
	for(int i=mid+1;i<=r;i++){
		sum[0][bmn[i]]++;
		sum[1][bmx[i]]++;
		for(auto j:q[i]){
			ans+=j.dlt*sum[j.id][j.x];
		}
		q[i].clear();
	}
	q[mid].clear();
	//exit(0);
	for(int i=mid+1;i<=r;i++){
		sum[0][bmn[i]]--;
		sum[1][bmx[i]]--;
		s[i]=0;
	}
	Solve(l,mid),Solve(mid+1,r);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	Solve(1,n),cout<<ans;
}