#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,L,a[300005],ans[300005];
pair<int,int> b[300005];
ll T,cnt;
int main(){
	cin>>n>>L>>T;
	for(int i=0;i<n;i++){
		cin>>a[i],a[i]--,b[i]=make_pair(a[i],i);
		ll w;
		char ch;
		cin>>ch;
		if(ch=='R')w=a[i]+T,a[i]=(a[i]+T)%L;
		else w=a[i]-T,a[i]=(a[i]-T)%L,a[i]=(a[i]+L)%L;
		if(w>0)cnt+=w/L;
		else cnt-=(-w+L-1)/L;
		cnt%=n;
	}
	sort(a,a+n),sort(b,b+n);
	for(int i=0;i<n;i++)ans[b[i].second]=a[((i+cnt)%n+n)%n]+1;
	for(int i=0;i<n;i++)cout<<ans[i]<<' ';
}