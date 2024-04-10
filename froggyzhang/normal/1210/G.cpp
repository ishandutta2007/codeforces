#include<bits/stdc++.h>
using namespace std;
#define N 35555
typedef long long ll;
const int inf=0x3f3f3f3f;
int n,a[N],l[N],r[N];
ll calc(int zz){
	priority_queue<ll> A; // Left
	priority_queue<ll,vector<ll>,greater<ll> > B; // right
	ll dl=0,dr=0,ans=0;
	for(int i=1;i<=n;++i)A.push(zz),B.push(zz);
	for(int i=1;i<=n;++i){
		dl+=a[i]-r[i],dr+=a[i]-l[i];
		int L=A.top()+dl,R=B.top()+dr;
		if(L<=0&&R>=0){
			A.push(-dl),B.push(-dr);
		}
		else if(L>0){
			ans+=L,B.push(L-dr),A.pop(),A.push(-dl),A.push(-dl);
		}
		else{
			ans-=R,A.push(R-dl),B.pop(),B.push(-dr),B.push(-dr);
		}
	}
	while(!A.empty()&&zz<A.top()+dl)ans+=(A.top()+dl)-zz,A.pop();
	while(!B.empty()&&zz>B.top()+dr)ans+=zz-(B.top()+dr),B.pop();
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>l[i]>>r[i];
	}
	int tot=accumulate(a+1,a+n+1,0);
	int l=-tot,r=tot+1;
	ll ans=LONG_LONG_MAX;
	while(l<r){
		int mid=(l+r)>>1;
		ll d1=calc(mid),d2=calc(mid+1);
		ans=min(ans,min(d1,d2));
		if(d1<=d2)r=mid;
		else l=mid+1;
	}
	cout<<ans<<'\n';
	return 0;
}