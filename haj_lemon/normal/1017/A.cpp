#include<bits/stdc++.h>
using namespace std;
int a[100010],x,y,z,p,ans=1,n;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){cin>>x>>y>>z>>p;a[i]=x+y+z+p;}
	for (int i=1;i<=n;i++) if (a[i]>a[1]) ans++;
	cout<<ans<<endl;
	return 0;
}