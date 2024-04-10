#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],st[N],top,f[N],g[N],d[N];
int Insert(int x){
	int t=0;
	while(top&&x<st[top])t=max(t,d[top--]+1);
	t=max(top+1,t);
	st[++top]=x,d[top]=t;
	return t;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int p1=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==1)p1=i;
	}
	rotate(a+1,a+p1,a+n+1);
	for(int i=1;i<=n;++i)f[i]=max(f[i-1],Insert(a[i]));
	top=0;
	for(int i=n;i>=1;--i)g[i]=max(g[i+1],Insert(a[i]));
	int mn=n+1,ans=-1;
	for(int i=0;i<=n;++i){
		int w=max(f[i],g[i+1]+1);
		if(w<mn)mn=w,ans=i;
	}
	cout<<mn<<' '<<(p1+ans-1)%n<<'\n';
	return 0;
}