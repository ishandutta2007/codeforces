#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int N=510000,inf=1e9,mod=998244353;
int n,cnt[105],b[200005];
ll a[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ll x=a[i],t=0;
		while(x%2==0)x>>=1,t++;
		b[i]=t,cnt[t]++;
	}
	int mx=0,p=0;
	for(int i=0;i<62;i++)if(cnt[i]>mx)mx=cnt[i],p=i;
	cout<<n-mx<<'\n';
	for(int i=1;i<=n;i++)if(b[i]!=p)cout<<a[i]<<' ';
}