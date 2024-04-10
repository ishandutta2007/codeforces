#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,m,f[200005],p[200005],g[200005][2];
struct Thing{
	ll id,x,tp;
	bool operator <(const Thing p) const {
		return x>p.x;
	}
}a[200005];
ll calc(int i,int n){
	if(i>2*m||n<=0)return 0;
	ll ans=0;
	if(a[i].tp==1){
		ans+=a[i].x,n--;
		if(p[a[i].id])return ans+a[p[a[i].id]].x*n;
		else {
			f[a[i].id]=1;
			return ans+calc(i+1,n);
		}
	}
	if(a[i].tp==2){
		if(f[a[i].id]){
			ans+=n*a[i].x,n=0;
			return ans;
		}
		else {
			ll tmp=ans+g[a[i].id][0]+(n-1)*g[a[i].id][1];
			p[a[i].id]=i;
			return max(tmp,ans+calc(i+1,n));
		}
	}
	//cout<<i<<' '<<a[i].id<<' '<<a[i].x<<' '<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>N>>m;
		for(int i=1;i<=m;i++){
			cin>>g[i][0]>>g[i][1];
			a[i]={i,g[i][0],1},a[i+m]={i,g[i][1],2};
		}
		sort(a+1,a+2*m+1);
		cout<<calc(1,N)<<endl;
		for(int i=1;i<=2*m;i++)f[i]=p[i]=0;
	}
}