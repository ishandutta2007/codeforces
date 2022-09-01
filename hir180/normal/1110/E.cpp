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
int c[100005],t[100005];
vector<int>a,b;
ll x,y;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		if(i) a.pb(c[i]-c[i-1]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&t[i]);
		if(i) b.pb(t[i]-t[i-1]);
	}
	SORT(a); SORT(b);
	if(a == b && c[0] == t[0] && c[n-1] == t[n-1]) puts("Yes");
	else puts("No");
}