#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n==1||(n==2&&a[1]==a[2])) cout<<"-1"<<endl;
	else{
		int x=2147483647,y;
		for (int i=1;i<=n;i++){
			if (a[i]<x) x=a[i],y=i;
		}
		cout<<n-1<<endl;
		for (int i=1;i<=n;i++) if (i!=y) cout<<i<<' ';cout<<endl;
	}
	return 0;
}