#include<iostream>
using namespace std;
typedef long long ll;
ll f[1000005][2],c1,c2,c3,d,a[1000005];
int n;
int main(){
	ios::sync_with_stdio(0),cin>>n>>c1>>c2>>c3>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[1][0]=c1*a[1]+c3,f[1][1]=min(c2,c1*(a[1]+1));
	for(int i=1;i<n;i++){
		f[i+1][1]=f[i][0]+min(c2,c1*(a[i+1]+1))+d;
		f[i+1][1]=min(f[i+1][1],f[i][1]+d+min(c2,c1*(a[i+1]+1))+c1+2*d);
		f[i+1][0]=f[i][0]+c1*a[i+1]+c3+d;
		f[i+1][0]=min(f[i+1][0],f[i][1]+d+c1*a[i+1]+c3+d+c1+d);
		f[i+1][0]=min(f[i+1][0],f[i][1]+d+min(c2,c1*(a[i+1]+1))+2*d+2*c1);
	}
	cout<<min(f[n][0],f[n-1][1]+d+c1*a[n]+c3+d+c1);
    return 0;
}