#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005],b[200005],c[200005],t[200005],ans=0,ansp=0;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i],t[++t[0]]=a[i],t[++t[0]]=b[i];
	sort(t+1,t+t[0]+1);
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(t+1,t+t[0]+1,a[i])-t,b[i]=lower_bound(t+1,t+t[0]+1,b[i])-t;
		c[a[i]]++,c[b[i]]--;
	}
	for(int i=1;i<=t[0];i++){
		c[i]+=c[i-1];
		if(c[i]>ans)ans=c[i],ansp=t[i];
	}
	cout<<ansp<<' '<<ans;
}