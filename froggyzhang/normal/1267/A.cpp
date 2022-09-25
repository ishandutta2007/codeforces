#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=1e18+233;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
ll l[N],r[N],t[N],ans;
int n,a[N],b[N];
set<pair<ll,int> > A,B;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		l[i]=read(),r[i]=read(),t[i]=read();
		A.insert(make_pair(l[i]+t[i],i));
		a[i]=b[i]=i;
	}
	sort(a+1,a+n+1,[&](int i,int j){return l[i]<l[j];});
	sort(b+1,b+n+1,[&](int i,int j){return r[i]<r[j];});
	ll u=0;
	int an=1,bn=1;
	while(true){
		while(an<=n&&u>=l[a[an]]){
			A.erase(make_pair(l[a[an]]+t[a[an]],a[an]));
			B.insert(make_pair(t[a[an]],a[an]));
			++an;
		}
		while(bn<=n&&u+t[b[bn]]>r[b[bn]]){
			B.erase(make_pair(t[b[bn]],b[bn]));	
			++bn;
		}
		if(A.empty()&&B.empty())break;
		ll z=(A.empty()?inf:A.begin()->first);
		if(B.empty()||u+(B.begin()->first)>=z){
			u=A.begin()->first;
			++ans;
			continue;	
		}
		ll h=B.begin()->first;
		ll lim=min(z,r[B.begin()->second]);
		ll c=(lim-u)/h;
		ans+=c;
		u+=c*h;
	}
	printf("%lld\n",ans);
	return 0;
}