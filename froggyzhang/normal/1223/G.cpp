#include<bits/stdc++.h>
using namespace std;
#define N 500055
const int B=5e5;
typedef long long ll;
int s[N<<1],a[N],n;
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int mx=0,se=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++s[a[i]];
		if(a[i]>mx)se=mx,mx=a[i];
		else se=max(se,a[i]);	
	}
	for(int i=1;i<=B+B;++i)s[i]+=s[i-1];
	for(int t=2;t<=mx;++t){
		int l=2,r=B+2,d=0;
		auto check=[&](int z)->bool{
			if(mx/z+se/z<2)return false;
			int lim=(z<<1)/t;
			ll cnt=-lim;
			int ok=0,jb=(z<<1)%t;
			for(int j=0;j*t<=B;++j){
				cnt+=1LL*j*(s[j*t+t-1]-s[max(j*t-1,0)]);
				if(j>=lim)ok+=max(0,s[j*t+t-1]-s[max(j*t+jb-1,0)]);
			}
			if(!ok)--cnt;
			if(cnt>=z)return true;
			lim=z/t;
			cnt=-lim*2,ok=0,jb=z%t;
			for(int j=0;j*t<=B;++j){
				cnt+=1LL*j*(s[j*t+t-1]-s[max(j*t-1,0)]);
				if(j>=lim)ok+=max(0,s[j*t+t-1]-s[max(j*t+jb-1,0)]);
			}
			if(ok<2)cnt-=2-ok;
			return cnt>=z;
		};
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)){
				d=mid,l=mid+1;
			}
			else{
				r=mid;
			}	
		}
		ans=max(ans,1LL*d*t);
	}
	cout<<ans<<'\n';
	return 0;
}