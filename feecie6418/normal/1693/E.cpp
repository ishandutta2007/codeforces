#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,a[200005],c[200005];
ll ans=0;
void U(int x,int y){
	while(x<=n)c[x]+=y,x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
vector<int> p[200005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],p[a[i]].push_back(i);
	for(int i=n,L=n,R=1;i>=1;i--){
		if(!p[i].size())continue;
		for(int j:p[i])U(j,1);
		int tl=p[i][0],tr=p[i].back(),l=L,r=R;
		L=min(tl,r+1),R=max(tr,l-1);
		ans+=Q(R)-Q(L-1);
	}
	cout<<ans;
}