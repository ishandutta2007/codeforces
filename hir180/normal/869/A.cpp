#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
int n,a[3005],b[3005];
bool used[5000005];
int main(){
	cin>>n;
	rep(i,n)cin>>a[i],used[a[i]]=1;
	rep(i,n)cin>>b[i],used[b[i]]=1;
	int ans = 0;
	rep(i,n)rep(j,n){
		ans += used[(a[i]^b[j])];
	}//cout<<ans<<endl;
	puts(ans%2==0?"Karen":"Koyomi");
}