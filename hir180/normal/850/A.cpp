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
int n,x[1005][5];
int main(){
	cin>>n;
	repn(i,n){
		rep(j,5) cin>>x[i][j];
	}
	if(n>=250){
		puts("0"); return 0;
	}
	vector<int>vi;
	repn(i,n){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(i==j || i==k) continue;
				int a[5],b[5],R=0;
				rep(q,5){
					a[q] = x[j][q]-x[i][q];
					b[q] = x[k][q]-x[i][q];
					R+=a[q]*b[q];
				}
				if(R>0) goto out;
			}
		}
		vi.pb(i); out:;
	}
	cout<<vi.size()<<endl;
	rep(i,vi.size())cout<<vi[i]<<endl;
}