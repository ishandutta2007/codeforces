#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
typedef unsigned long long ull;
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
int n,a[N],ans;
ull t[N],s[N];
mt19937 rnd(time(0));
inline ull Get(){
	return (ull)rnd()*rnd()+rnd();	
}
void Solve(int l,int r){
	if(l==r){ans+=a[l]==1;return;}
	int mid=(l+r)>>1;
	Solve(l,mid),Solve(mid+1,r);
	ull L=0,R=0;
	static int visl[N],visr[N];
	unordered_map<ull,int> mp;
	for(int i=mid+1,j=mid,mx=0;i<=r;++i){
		if(visr[a[i]])break;
		visr[a[i]]=1;
		mx=max(mx,a[i]);
		R^=t[a[i]];
		while(j>=l&&a[j]<=mx){
			if(visl[a[j]]){
				j=l-1;break;
			}
			visl[a[j]]=1;
			L^=t[a[j--]];
			++mp[L];
		}
		ans+=mp[s[mx]^R];
	}
	for(int i=mid;i>=l;--i)visl[a[i]]=0;
	for(int i=mid+1;i<=r;++i)visr[a[i]]=0;
	L=R=0;
	mp.clear();
	for(int i=mid,j=mid+1,mx=0;i>=l;--i){
		if(visl[a[i]])break;
		visl[a[i]]=1;
		mx=max(mx,a[i]);
		L^=t[a[i]];
		while(j<=r&&a[j]<=mx){
			if(visr[a[j]]){
				j=r+1;break;
			}
			visr[a[j]]=1;
			R^=t[a[j++]];
			++mp[R];
		}
		ans+=mp[s[mx]^L];
	}
	for(int i=mid;i>=l;--i)visl[a[i]]=0;
	for(int i=mid+1;i<=r;++i)visr[a[i]]=0;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		t[i]=Get();
	}
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]^t[i];
	}
	Solve(1,n);
	printf("%d\n",ans);
	return 0;
}