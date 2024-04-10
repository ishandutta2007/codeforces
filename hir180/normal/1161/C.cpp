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
int n;
vector<int>vec;

int main(){
	cin>>n;
	rep(i,n){
		int a; cin>>a; vec.pb(a);
	}
	SORT(vec);
	int N = vec[0]-1;
	rep(i,n) vec[i] -= N;
	int cnt = 0;
	rep(i,n){
		cnt += vec[i] == 1;
	}
	if(cnt >= n/2+1) cout<<"Bob"<<endl;
	else cout<<"Alice"<<endl;
}