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
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int t;
int main(){
	cin>>t;
	rep(eee,t){
		int n; cin>>n;
		if(n && n<4){
			puts("N");
		}
		else{
			double d = (double)(n);
			printf("Y ");
			printf("%.10f ",(d-sqrt(d*d-4*d))/2.0);
			printf("%.10f\n",(d+sqrt(d*d-4*d))/2.0);
		}
	}
}