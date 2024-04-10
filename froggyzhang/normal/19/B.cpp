#include<iostream>
using namespace std;
#define MAX 99999999999999
int n;
struct product{
	int t,value;
}a[2005];
long long f[4500],minn=MAX;
int m=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].value;
		a[i].t++;
		m=max(m,a[i].t);
	}
	m+=n;
	for(int i=1;i<=m;i++){
		f[i]=MAX;
	}
	f[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i].t;j--){
			f[j]=min(f[j],f[j-a[i].t]+a[i].value);
			if(j>=n)minn=min(minn,f[j]);
		}
	}
	cout<<minn;
	return 0;
}