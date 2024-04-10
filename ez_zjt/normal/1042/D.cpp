#include <bits/stdc++.h>
#define MAXN 200010
#define LL long long
using namespace std;

int n;
LL lim,a[MAXN],s[MAXN];
LL ans;

void solve(int l,int r){
	if(l==r){
		if(a[l]<=lim) ans++;
		return;
	}
	int mid=(l+r)>>1;
	solve(l,mid); solve(mid+1,r);
	static LL b[MAXN],c[MAXN];
	int n1=0,n2=0;
	for(int i=l;i<=mid;i++) b[++n1]=s[i-1];
	for(int i=mid+1;i<=r;i++) c[++n2]=s[i];
	sort(b+1,b+n1+1);
	sort(c+1,c+n2+1);
	int now=1;
	for(int i=1;i<=n2;i++){
		while(now<=n1 && c[i]-b[now]>lim) now++;
		ans+=n1-now+1;
	}
}

int main(){
	cin>>n>>lim;
	lim--;
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		a[i]=t;
		s[i]=s[i-1]+a[i];
	}
	solve(1,n);
	cout<<ans<<endl;
}