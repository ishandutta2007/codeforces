#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n;
ll a[N],X;
struct Line{
	int l,r;
	friend bool operator < (const Line &a,const Line &b){
		return a.r^b.r?a.r<b.r:a.l<b.l;
	}
}c[N];
int st[N],top,tot;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>X;
	for(int i=1;i<=n;++i){
		a[i]=a[i]-X+a[i-1];
	}
	top=tot=0;
	for(int i=0;i<=n;++i){
		int l=0,r=top+1,pos=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[st[mid]]>a[i])pos=mid,l=mid+1;
			else r=mid;
		}
		if(pos)c[++tot]={st[pos]+1,i};
		if(i){
			while(top&&a[st[top]]<=a[i-1])--top;
			st[++top]=i-1;
		}
	}
	sort(c+1,c+tot+1);
	int zz=-1,jb=0;
	for(int i=1;i<=tot;++i){
		if(zz<c[i].l)zz=c[i].r,++jb;
	}
	cout<<n-jb<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}