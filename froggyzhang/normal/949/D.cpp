#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,d,b,a[N];
bool check(int x){
	int now=0;
	for(int i=1;i<=x;++i)now+=a[i];
	for(int i=x+1,j=x+1;i<=(n+1)/2;++i){
		while(j<=n&&(j-i)<=1LL*i*d)now+=a[j++];
		if(now<b)return false;
		now-=b;
	}
	now=0;
	for(int i=n;i>n-x;--i)now+=a[i];
	for(int i=n-x,j=n-x;i>(n+1)/2;--i){
		while(j>=1&&(i-j)<=1LL*(n-i+1)*d)now+=a[j--];
		if(now<b)return false;
		now-=b;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>d>>b;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int l=0,r=(n+1)/2+1,ans=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}