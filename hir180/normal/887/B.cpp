#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
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
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int x[5][10];
int main(){
	int n; cin>>n;
	rep(i,n)rep(j,6)cin>>x[i][j];
	set<int>S;
	int a[5];
	rep(i,n)a[i]=i;
	do{
		vector<int>val;
		val.pb(0);
		for(int j=0;j<n;j++){
			int g=val.size();
			for(int k=0;k<g;k++){
				for(int aa=0;aa<6;aa++){
					val.pb(val[k]*10+x[a[j]][aa]);
				}
			}
			SORT(val); ERASE(val);
		}
		rep(i,val.size()) S.insert(val[i]);
	}while(next_permutation(a,a+n));
	repn(i,10000){
		if(S.find(i) == S.end()){
		
			cout<<i-1<<endl;
			return 0;
		}
	}
}