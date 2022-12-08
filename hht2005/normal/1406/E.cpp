#include<bits/stdc++.h>
using namespace std;
const int pps=1e6;
int f[pps+10],p[pps+10];
int main() {
	int n,x,ans=1,tot=0,i;
	scanf("%d",&n);
	for(i=2;i<=n;i++) {
		if(!f[i])p[++tot]=i;
		for(int j=1;j<=tot&&p[j]*i<=n;j++) {
			f[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	for(i=1;i<=tot&&p[i]*p[i]<=n;i++) {
		cout<<"B "<<p[i]<<endl;
		cin>>x;
		for(int k=p[i];k<=n;k*=p[i]) {
			cout<<"A "<<k<<endl;
			cin>>x;
			if(!x)break;
			ans*=p[i];
		}
	}
	cout<<"A 1"<<endl;
	cin>>x;
	int sum=x;
	for(i--;i<=tot;i+=100) {
		int R=min(tot,i+100);
		for(int j=i+1;j<=R;j++) {
			cout<<"B "<<p[j]<<endl;
			cin>>x;//sgrdtf
			if(x==2) {
				ans*=p[j];
				goto A;
			}
			sum--;
		}
		cout<<"A 1"<<endl;
		cin>>x;
		if(x!=sum) {
			for(int j=i+1;j<=R;j++) {
				cout<<"B "<<p[j]<<endl;
				cin>>x;
				if(x)ans*=p[j];
			}
			break;
		}
	}A:
	cout<<"C "<<ans<<endl;
	return 0;
}