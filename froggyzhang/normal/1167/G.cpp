#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1.0);
#define N 200010
typedef long long ll;
int n,d,a[N],m,c[N];
double g[N];
inline int Abs(int x){return x>=0?x:-x;}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(10);
	cin>>n>>d;
	g[0]=PI/2;
	for(int i=1;i<=200000;++i){
		g[i]=atan(1.0/i);
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>c[i];
	}
	for(int t=1,i=0;t<=m;++t){
		while(i<n&&a[i+1]+1<=c[t])++i;
		if(a[i]+1==c[t]&&a[i+1]==c[t]){
			cout<<PI<<'\n';
			continue;
		}
		double ans=0;
		if(i>=1)ans=max(ans,g[c[t]-a[i]-1]);
		if(i<n)ans=max(ans,g[a[i+1]-c[t]]);
		bool ok=false;
		for(int j=i,k=i+1;j>=1&&c[t]-a[j]<=2*d+1&&k<=n&&!ok;--j){
			while(k<=n&&a[k]-c[t]<=c[t]-a[j]-1){
				if(Abs((a[k]-c[t])-(c[t]-a[j]-1))<=1){
					ans=max(ans,g[c[t]-a[j]-1]*2);ok=true;
					break;
				}
				++k;
			}
			if(ok)break;
			if(k<=n&&Abs((a[k]-c[t])-(c[t]-a[j]-1))<=1){
				ans=max(ans,g[a[k]-c[t]]*2);
				ok=true;
			}
		}
		
		/*
		for(int j=1;j<=i;++j){
			for(int k=i+1;k<=n;++k){
				ans=max(ans,g[max(a[k]-c[t],c[t]-a[j]-1)]*2);	
			}	
		}
		*/
		cout<<ans<<'\n';
	}
	return 0;
}