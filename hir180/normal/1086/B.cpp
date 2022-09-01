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
double x;
int deg[100005];
int main(){
	scanf("%d%lf",&n,&x);
	for(int i=1;i<n;i++){
		int a,b; scanf("%d%d",&a,&b);
		deg[a]++;
		deg[b]++;
	}
	double hoge = 0.0;
	repn(i,n) if(deg[i] == 1) hoge += 1.0;
	printf("%.12f\n",2.0*x/hoge);
}