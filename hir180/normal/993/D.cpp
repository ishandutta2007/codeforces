#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define double long double
int n,a[55],b[55];
double dp[55][55];
map<int,vector<int> >M;

int main(){
	cin>>n;
	repn(i,n) cin>>a[i];
	repn(i,n){
		cin>>b[i];
		M[-a[i]].pb(b[i]);
	}
	double lb = 0.0,ub = 3e8;
	rep(i,205){
		double mid = (lb+ub)/2;
		rep(i,55)rep(j,55) dp[i][j] = 1e9;
		dp[0][0] = 0;
		int nxt = 1;
		for(map<int,vector<int> >::iterator it=M.begin();it!=M.end();++it){
			vector<int>hoge = it->sc;
			SORT(hoge);
			for(int j=0;j<55;j++){
				if(dp[nxt-1][j] > 5e8) continue;
				double sum = 0.0,sum2 = 0.0;
				for(int i=0;i<=hoge.size();i++){
					int zan = hoge.size()-i;
					if(j>=zan){
						dp[nxt][j-zan+i] = min(dp[nxt][j-zan+i],dp[nxt-1][j]+sum-sum2*mid);
					}
					if(i==hoge.size()) break;
					sum -= (double)(it->fi);
					sum2 += (double)(hoge[hoge.size()-1-i]);
				}
			}
			nxt++;
		}
		for(int j=0;j<55;j++){
			if(dp[nxt-1][j] < -1e-18){
				ub = mid;
				goto nxt;
			}
		}
		lb = mid; nxt:;
	}
	double hoge = ub*1000.0;
	hoge -= 1e-4;
	printf("%lld\n",(ll)ceil(hoge));
}