#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=35005;typedef long long ll;
int a[N],l[N],r[N],n;ll v,tag1,tag2;
std::priority_queue<ll> q1;
std::priority_queue<ll,std::vector<ll>,std::greater<ll>> q2;
ll calc(int mid){
	tag1=tag2=v=0,l[1]-=mid,r[1]-=mid,l[n]+=mid,r[n]+=mid;
	while(!q1.empty())q1.pop();
	while(!q2.empty())q2.pop();
	for(int i=1;i<=n;++i)q1.push(0),q2.push(0);
	for(int i=1;i<=n;++i){
		tag1+=l[i],tag2+=r[i];ll L=q1.top()+tag1,R=q2.top()+tag2;
		if(L<=0&&R>=0)q1.push(-tag1),q2.push(-tag2);
		else if(L>0)q2.push(L-tag2),q1.pop(),q1.push(-tag1),q1.push(-tag1),v+=L;
		else q1.push(R-tag1),q2.pop(),q2.push(-tag2),q2.push(-tag2),v-=R;
	}
	ll L=q1.top()+tag1,R=q2.top()+tag2,ans=v+(mid>0?mid:-mid);
	if(L>0){
		ll cur=L,d=0;q1.pop();
		while(!q1.empty()){
			ll x=q1.top()+tag1;q1.pop();++d;
			if(x<=0){ans+=cur*d;break;}
			else ans+=(cur-x)*d,cur=x;
		}
	}
	if(R<0){
		ll cur=R,d=0;q2.pop();
		while(!q2.empty()){
			ll x=q2.top()+tag2;q2.pop();++d;
			if(x>=0){ans+=-cur*d;break;}
			else ans+=(x-cur)*d,cur=x;
		}
	}
	l[1]+=mid,r[1]+=mid,l[n]-=mid,r[n]-=mid;
	return ans;
}
int main(){
	read(n);ll s=0;for(int i=1;i<=n;++i)read(a[i],l[i],r[i]),s+=a[i],l[i]-=a[i],r[i]-=a[i];
	ll l=-s,r=s,mid;while(r-l>3){mid=l+(r-l)/2;if(calc(mid)<calc(mid+1))r=mid;else l=mid+1;}
	ll ans=1e18;for(ll i=l;i<=r;++i)ans=std::min(ans,calc(i));
	printf("%lld\n",ans);
	return 0;
}