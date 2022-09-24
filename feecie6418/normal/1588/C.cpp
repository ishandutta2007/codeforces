#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;
int n,lg2[300005];
ll a[300005],c[300005],s[300005],ans,f[2][20][300005],sa[300005];
struct Query{
	ll x;
	int dlt,bel;
};
vector<Query> vec[300005];
map<ll,int> mp[2];
ll Qmn(int d,int l,int r){
	int k=lg2[r-l+1];
	return min(f[d][k][l],f[d][k][r-(1<<k)+1]);
}
void Solve(){
	scanf("%d",&n),ans=0,lg2[0]=-1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]),lg2[i]=lg2[i>>1]+1;
		c[i]=a[i]-a[i-1],sa[i]=sa[max(i-2,0)]+a[i];
		if(!a[i])ans++;
	}
	c[n+1]=-a[n];
	for(int i=1;i<=n;i++){
		s[i]=s[max(i-2,0)]+c[i];
		f[i&1][0][i]=s[i];
		f[(i&1)^1][0][i]=1e18;
	}
	for(int k=0;k<2;k++)for(int i=1;i<=18;i++)for(int j=1;j+(1<<i)-1<=n;j++)f[k][i][j]=min(f[k][i-1][j],f[k][i-1][j+(1<<i-1)]);
	for(int i=1;i<n;i++){
		int l=i,r=n,ans1=n+1,ans2=n,I=i&1,J=I^1;
		while(l<=r){
			int mid=(l+r)/2;
			if(Qmn(I,i,mid)<-(a[i]-s[i])){
				ans1=mid,r=mid-1;
			}
			else l=mid+1;
		}
		ans1--;
		//r<=ans1
		l=i+1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(Qmn(J,i,mid)<s[i-1]){
				ans2=mid,r=mid-1;
			}
			else l=mid+1;
		}
		//r<=ans2
		int w=min(ans1,ans2);
		if(w<=i)continue;
		if(w%2==i%2){
			vec[w].push_back({sa[max(i-2,0)]-sa[i-1],1,I});
			vec[i].push_back({sa[max(i-2,0)]-sa[i-1],-1,I});
			vec[w-1].push_back({sa[i-1]-sa[max(i-2,0)],1,J});
			vec[i-1].push_back({sa[i-1]-sa[max(i-2,0)],-1,J});
		}
		else {
			vec[w-1].push_back({sa[max(i-2,0)]-sa[i-1],1,I});
			vec[i].push_back({sa[max(i-2,0)]-sa[i-1],-1,I});
			vec[w].push_back({sa[i-1]-sa[max(i-2,0)],1,J});
			vec[i-1].push_back({sa[i-1]-sa[max(i-2,0)],-1,J});
		}
	}
	for(int i=1;i<=n;i++){
		mp[i&1][sa[i]-sa[i-1]]++;
		for(auto j:vec[i])ans+=j.dlt*mp[j.bel][j.x];
	}
	cout<<ans<<'\n';
	for(int i=0;i<=n;i++)vec[i].clear();
	mp[0].clear(),mp[1].clear();
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}