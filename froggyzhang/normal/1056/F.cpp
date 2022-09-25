#include<bits/stdc++.h>
using namespace std;
#define N 123
typedef long long ll;
const double eps=1e-9;
const double c=10/9.0;
const double inf=1e12;
int n,m;
struct Task{
	int w,p;	
}a[N];
double C,T,dp[N][N*10],pw[N];
void Solve(){
	cin>>n;
	cin>>C>>T;
	m=0;
	for(int i=1;i<=n;++i){
		cin>>a[i].w>>a[i].p;
		m+=a[i].p;
	}
	sort(a+1,a+n+1,[&](Task a,Task b){return a.w>b.w;});
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			dp[i][j]=inf;
	dp[0][0]=0;
	for(int k=1;k<=n;++k){
		for(int i=k;i>=1;--i){
			for(int j=a[k].p;j<=m;++j){
				dp[i][j]=min(dp[i][j],dp[i-1][j-a[k].p]+pw[i]*a[k].w);	
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(T<10*i)break;
		for(int j=m;j>=1;--j){
			if(dp[i][j]<inf){
				auto F = [&](double x) -> double{
					return 10*i+x+dp[i][j]/(1+C*x);
				};
				double l=0,r=T-10*i,mn=inf;
				while(r-l>eps){
					double mid1=(l+l+r)/3.0;
					double mid2=(l+r+r)/3.0;
					double d1=F(mid1),d2=F(mid2);
					mn=min(mn,min(d1,d2));
					if(d1<=d2)r=mid2;
					else l=mid1;
				}
				if(mn<=T){ans=max(ans,j);break;}
			}	
		}		
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	pw[0]=1;
	for(int i=1;i<=100;++i)pw[i]=pw[i-1]*c;
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}