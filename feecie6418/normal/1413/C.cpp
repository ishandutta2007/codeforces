#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
struct Thing{
	int id,x;
}b[600005];
int a[10],n,ans=1e9,m,c[100005],sum;
void Add(int x,int y){
	if(!c[b[x].id])sum++;
	c[b[x].id]+=y;
	if(!c[b[x].id])sum--;
}
int main() {
	for(int i=1; i<=6; i++)cin>>a[i];
	cin>>n;
	for(int i=1,x; i<=n; i++){
		cin>>x;
		for(int j=1;j<=6;j++)b[++m]={i,x-a[j]};
	}
	sort(b+1,b+m+1,[](Thing i,Thing j){return i.x<j.x;});
	for(int i=1,j=0;i<=m;i++){
		while(sum<n&&j<m)Add(++j,1);
		if(sum==n)ans=min(ans,b[j].x-b[i].x);
		Add(i,-1);
	}
	cout<<ans;
}