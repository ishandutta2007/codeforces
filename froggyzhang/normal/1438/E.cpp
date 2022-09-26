#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200020
const int inf=1<<30;
typedef long long ll;
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
int n,a[N];
ll ans;
void Solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	Solve(l,mid),Solve(mid+1,r);
	static int vis[N];
	for(int i=mid;i>=l;--i)vis[i]=0;
	for(int i=mid,s1=0;i>=l;--i){
		if(s1>=inf)break;
		if(a[i]>=s1){
			vis[i]=1;
			for(int j=mid+1,s2=0;j<=r;++j){
				if(s2>=inf)break;
				if(s1+s2==(a[i]^a[j]))++ans;
				s2+=a[j];
			}
		}
		s1+=a[i];
	}
	for(int i=mid+1,s1=0;i<=r;++i){
		if(s1>=inf)break;
		if(a[i]>=s1){
			for(int j=mid,s2=0;j>=l;--j){
				if(s2>=inf)break;
				if(vis[j])goto myh;
				if(s1+s2==(a[i]^a[j]))++ans;
				myh:
				s2+=a[j];
			}
		}
		s1+=a[i];
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	Solve(1,n);
	for(int i=1;i<n;++i){
		ans-=(a[i]==a[i+1]);
	}
	printf("%lld\n",ans);
	return 0;
}