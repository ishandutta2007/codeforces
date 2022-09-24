#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,m;
ll f[4005][4005],t[8005],a[4005];
void upd(ll &x,ll y){
	x=max(x,y);
}
int dp(int l,int r){
	int x=min_element(a+l,a+r+1)-a;
	f[x][0]=0;
	f[x][1]=(m-1)*a[x];
	if(l<x){
		int q=dp(l,x-1);
		memset(t,0xc0,sizeof(t));
		for(int i=0;i<=1;i++){
			for(int j=0;j<=x-l;j++){
				upd(t[i+j],f[x][i]+f[q][j]-2*i*j*a[x]);
			}
		}
		for(int i=0;i<=x-l+1;i++)f[x][i]=t[i];
	}
	if(x<r){
		int q=dp(x+1,r);
		memset(t,0xc0,sizeof(t));
		for(int i=0;i<=x-l+1;i++){
			for(int j=0;j<=r-x;j++){
				upd(t[i+j],f[x][i]+f[q][j]-2*i*j*a[x]);
			}
		}
		for(int i=0;i<=r-l+1;i++)f[x][i]=t[i];
	}
	return x;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<f[dp(1,n)][m];
}