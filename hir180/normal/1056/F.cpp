#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int tc;
int n,p[105];
double C,T,a[105];
double dp[2][1055][105];
double fc[1005];
int x;
void kaede(){
	cin>>n;
	scanf("%lf%lf",&C,&T);
	vector<pair<double,int> >vec;
	for(int i=0;i<n;i++){
		double aw; int pw;
		scanf("%lf%d",&aw,&pw);
		vec.pb(mp(-1.0*aw,pw));
	}
	SORT(vec);
	for(int i=0;i<n;i++){
		a[i] = -1.0*vec[i].fi;
		p[i] = vec[i].sc;
	}
	rep(a,2)rep(b,1055)rep(c,105)dp[a][b][c]=1e18;
	int cur = 0, nxt = 1;
	dp[0][0][0] = 0.0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=10*(1+i);j++) for(int k=0;k<=(i+1);k++) dp[nxt][j][k] = 1e18;
		for(int j=0;j<=10*i;j++) for(int k=0;k<=i;k++){
			if(dp[cur][j][k] > 1e14) continue;
			dp[nxt][j][k] = min(dp[nxt][j][k],dp[cur][j][k]);
			dp[nxt][j+p[i]][k+1] = min(dp[nxt][j+p[i]][k+1],dp[cur][j][k]+a[i]/fc[k+1]);
		}
		swap(cur,nxt);
	}
	for(int j=10*n;j>=0;j--){
		for(int k=0;k<=n;k++){
		    if(dp[cur][j][k] > 1e14) continue;
		    if(dp[cur][j][k]+1e-15 > 1.0/C){
			    if(2.0*sqrt(dp[cur][j][k]/C)-1.0/C > T-10.0*(double)(k)+1e-15) continue;
			    cout<<j<<endl; return ;
		    }
		    else{
		        if(dp[cur][j][k] > T-10.0*(double)(k)+1e-15) continue;
			    cout<<j<<endl; return ;
		    }
		}
	}
	cout<<0<<endl; return ;
}
int main(){
	fc[0] = 1;
	for(int i=1;i<=1000;i++) fc[i] = fc[i-1]*0.9;
	cin>>tc;
	while(tc--) kaede();
}