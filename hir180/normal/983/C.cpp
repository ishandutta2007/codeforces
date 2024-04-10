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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int dp[2005][805][11],n,a[2005],b[2005];
int num[10005],go[10005][10],go2[10005][10];
vector<int>zip;
int rec(int numm,int mask,int pos){
	if(numm == n && num[zip[mask]] == 0) return 0;
	if(dp[numm][mask][pos] <= 5e8) return dp[numm][mask][pos];
	for(int i=1;i<=9;i++){
		if(go[zip[mask]][i] == -1) continue;
		int to = POSL(zip,go[zip[mask]][i]);
		assert(zip[to] == go[zip[mask]][i]);
		dp[numm][mask][pos] = min(dp[numm][mask][pos],rec(numm,to,i)+abs(pos-i));
	}
	if(numm != n && num[zip[mask]] != 4){
	    if(go2[zip[mask]][b[numm+1]] != -1){
    		int to = POSL(zip,go2[zip[mask]][b[numm+1]]);
    		assert(zip[to] == go2[zip[mask]][b[numm+1]]);
    		dp[numm][mask][pos] = min(dp[numm][mask][pos],rec(numm+1,to,a[numm+1])+abs(pos-a[numm+1]));
	    }
	}
	return dp[numm][mask][pos];
}
int main(){
	cin>>n;
	repn(i,n) cin>>a[i]>>b[i];
	for(int i=0;i<=9999;i++){
		int j = i; 
		int d = j%10; j/=10;
		int c = j%10; j/=10;
		int b = j%10; j/=10;
		int a = j%10; j/=10;
		if(a>b||b>c||c>d) continue;
		zip.pb(i);
		num[i]+=!!a;
		num[i]+=!!b;
		num[i]+=!!c;
		num[i]+=!!d;
		for(int ii=1;ii<=9;ii++){
			vector<int>nw;
			if(a != ii) nw.pb(a);
			if(b != ii) nw.pb(b);
			if(c != ii) nw.pb(c);
			if(d != ii) nw.pb(d);
			if(nw.size() == 4){
				go[i][ii] = -1;
			}
			else{
				while(nw.size() != 4) nw.pb(0);
				SORT(nw);
				int cc = 0;
				for(int i=0;i<nw.size();i++){
					cc = cc*10+nw[i];
				}
				go[i][ii] = cc;
			}
		}
		for(int ii=1;ii<=9;ii++){
			vector<int>nw;
			if(a != 0) nw.pb(a);
			if(b != 0) nw.pb(b);
			if(c != 0) nw.pb(c);
			if(d != 0) nw.pb(d);
			if(nw.size() == 4){
				go2[i][ii] = -1;
			}
			else{
				while(nw.size() != 3) nw.pb(0);
				while(nw.size() != 4) nw.pb(ii);
				SORT(nw);
				int cc = 0;
				for(int i=0;i<nw.size();i++){
					cc = cc*10+nw[i];
				}
				go2[i][ii] = cc;
			}
		}
	}
	rep(a,2005)rep(b,805)rep(c,11) dp[a][b][c] = INF;
	cout<<rec(0,0,1)+2*n<<endl;
}