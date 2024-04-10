#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=10005;typedef long long ll;
ll a[N],c[N];int L[N],R[N],st[N],top,LL[N],n;
int main(){
	read(n);for(int i=1;i<=n;++i)read(a[i]);
	st[top=0]=0;
	for(int i=1;i<=n;++i){
		while(top&&a[i]<=a[st[top]])--top;
		L[i]=st[top],st[++top]=i;
	}
	st[top=0]=n+1;
	for(int i=n;i>=1;--i){
		while(top&&a[i]<=a[st[top]])--top;
		R[i]=st[top],st[++top]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		int l=L[i]+1,r=R[i]-1;ll v=a[i],cur=1LL*v*(r-l+1),mx=0;
		for(int j=l;j<=r;++j)a[j]-=v;
		st[top=0]=0;
		for(int i=1;i<=n;++i){
			while(top&&a[i]<a[st[top]])mx=std::max(mx,1LL*a[st[top]]*(i-LL[st[top]]-1)),--top;
			LL[i]=st[top],st[++top]=i;
		}
		while(top)mx=std::max(mx,1LL*a[st[top]]*(i-LL[st[top]]-1)),--top;
		ans=std::max(ans,cur+mx);
		for(int j=l;j<=r;++j)a[j]+=v;
	}
	for(int i=1;i<=n;++i){
		int l=L[i]+1,r=R[i]-1;ll v=a[i];c[l]=c[r]=v;
		for(int i=l-1;i>=1;--i)c[i]=std::min(c[i+1],a[i]);
		for(int i=r+1;i<=n;++i)c[i]=std::min(c[i-1],a[i]);
		for(int p=1,q=r;p<=l;++p){
			ll lim=v-c[p];while(q<n&&a[q+1]>=lim)++q;
			ans=std::max(ans,1LL*(r-p+1)*c[p]+1LL*(q-l+1)*lim);
		}
		for(int p=n,q=l;p>=r;--p){
			ll lim=v-c[p];while(q>1&&a[q-1]>=lim)--q;
			ans=std::max(ans,1LL*(p-l+1)*c[p]+1LL*(r-q+1)*lim);
		}
	}
	printf("%lld\n",ans);
	return 0;
}