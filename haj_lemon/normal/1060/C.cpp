#include<bits/stdc++.h>
using namespace std;
int n,m,a[2010],b[2010],c[2010],d[2010],x,ansn;
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) a[i]+=a[i-1];
	for (int i=1;i<=m;i++) b[i]+=b[i-1];
	for (int i=1;i<=max(m,n);i++) c[i]=d[i]=1e9;
	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++)c[i-j]=min(c[i-j],a[i]-a[j]);
	for (int i=1;i<=m;i++)
		for (int j=0;j<i;j++)d[i-j]=min(d[i-j],b[i]-b[j]);
	cin>>x;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (x/c[i]>=d[j])ansn=max(ansn,i*j);
		}
	}
	cout<<ansn<<endl;
	return 0;
}