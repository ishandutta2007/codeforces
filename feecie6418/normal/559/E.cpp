#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct T{
	int fr,len;
}a[105];
int f[105][105][2],n,ans;
int main() {
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].fr>>a[i].len;
	sort(a+1,a+n+1,[](T i,T j){return i.fr<j.fr;}),a[0].fr=-1e9;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<2;k++){
				ans=max(ans,f[i][j][k]);
				int o=a[j].fr+a[j].len*k,mxp,mxf,mx=-1e9;
				for(int l=i+1;l<=n;l++){
					for(int p=0;p<2;p++){
						int z=a[l].fr+a[l].len*p;
						if(z>mx)mx=z,mxp=l,mxf=p;
						f[l][mxp][mxf]=max(f[l][mxp][mxf],f[i][j][k]+min(a[l].len,z-o)+mx-z);
					}
				}
			}
		}
	}
	cout<<ans;
}