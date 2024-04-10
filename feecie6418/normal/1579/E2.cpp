#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005],c[200005];
void U(int x,int k){
	while(x<=n)c[x]+=k,x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	long long ans=0;
	for(int i=1;i<=n;i++){
		int s1=i-1-Q(a[i]);// 
		int s2=Q(a[i]-1);//
		ans+=min(s1,s2);
		U(a[i],1); 
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)c[i]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}