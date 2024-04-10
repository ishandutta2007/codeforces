#include<bits/stdc++.h>
using namespace std;
int a[200000],all[200000];
int n;
long long ans;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=n;i>=2;i--)
		all[i]=max(a[i],all[i+1]-1);
	int u=0,d=0;
	for (int i=1;i<=n;i++){
		if (a[i]>u+d)u=a[i],d=0;
		else
		if (a[i]>=u){
			d-=a[i]-u,u=a[i];
		}else
			d+=u-a[i],u=a[i];
		if (u+d<all[i])d=all[i]-u;
		ans+=d;
	}
	cout<<ans;
	return 0;
}