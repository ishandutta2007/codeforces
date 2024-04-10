#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
int n,a[500005],c[500005],d[500005];
ll all;
void U(int x){
	while(x<=n)c[x]++,x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
void Solve(){
	scanf("%d",&n),all=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int prele=Q(a[i]),premo=i-1-prele;
		int sufle=a[i]-1-prele;
		d[i]=prele-premo+2*sufle;
		all+=premo,U(a[i]);
	}
	sort(d+1,d+n+1),cout<<all<<' ';
	for(int i=1;i<=n;i++)c[i]=0,all+=d[i],cout<<all-1ll*i*(i-1)/2<<' ';
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}