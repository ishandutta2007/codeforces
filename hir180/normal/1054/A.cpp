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
int x,y,z,t1,t2,t3;
int main(){
	cin>>x>>y>>z>>t1>>t2>>t3;
	int ans1 = abs(x-y)*t1;
	int ans2 = abs(z-x)*t2+t3+t3+abs(x-y)*t2+t3;
	//cout<<ans1 << " " << ans2 << endl;
	if(ans1 >= ans2) puts("YES");
	else puts("NO");
}