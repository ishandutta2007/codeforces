#include<bits/stdc++.h>
using namespace std;
int m,n,t[100005],x[100005],y[100005],f[100005],ans=0,mxf[100005];
int main() {
	memset(f,0xc0,sizeof(f));
	f[0]=0,x[0]=y[0]=1,cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>x[i]>>y[i];
		for(int j=i-1;j>=0;j--){
			if(t[j]<t[i]-1000){
				f[i]=max(f[i],mxf[j]+1);
				break;
			}
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])f[i]=max(f[i],f[j]+1);
		}
		ans=max(ans,f[i]);
		mxf[i]=max(mxf[i-1],f[i]);
	}
	cout<<ans;
}