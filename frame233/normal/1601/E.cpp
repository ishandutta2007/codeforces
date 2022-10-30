#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005;typedef std::pair<int,int> pi;typedef long long ll;
ll ans[N];std::vector<pi> Q[N];int a[N],b[N],_q[N],_l=1,_r;
struct node{int v,p,id;}st[N];int top;ll pre[N];
inline void push(int v,int p,int id){
	while(top&&v<st[top].v)--top;
	ll tmp=!top?0:1LL*(st[top].p-p)*v;
	st[++top]={v,p,id},pre[top]=pre[top-1]+tmp;
}
int main(){
	int n,q,k;read(n,q,k);
	for(int i=0;i<n;++i)read(a[i]);
	for(int i=n-1;i>=0;--i){
		while(_l!=_r+1&&_q[_l]-i>=k)++_l;
		while(_l!=_r+1&&a[i]<a[_q[_r]])--_r;
		_q[++_r]=i,b[i]=a[_q[_l]];
	}
	for(int i=0,l,r;i<q;++i)read(l,r),--l,--r,Q[l].pb({r,i});
	for(int s=n-1;s>=n-k;--s){
		top=0;
		for(int l=s;l>=0;l-=k){
			if(l!=s)--top,push(b[l+1],(l+k)/k,l+k);
			push(a[l],l/k,l);
			for(auto [r,id]:Q[l]){
				int L=1,R=top+1,mid;
				while(L<R)mid=(L+R)>>1,st[mid].id<=r?R=mid:L=mid+1;
				ans[id]=(L>=top?0:pre[top]-pre[L])+1LL*st[L].v*((r-st[L].id)/k+1);
			}
		}
	}
	for(int i=0;i<q;++i)printf("%lld\n",ans[i]);
	return 0;
}