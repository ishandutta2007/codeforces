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
int a[8],b[8];
bool in(int x,int y,int mode){
	if(mode == 0){
		int mn = min(min(a[0],a[2]),min(a[4],a[6]));
		int mx = max(max(a[0],a[2]),max(a[4],a[6]));
		int mn2 = min(min(a[1],a[3]),min(a[5],a[7]));
		int mx2 = max(max(a[1],a[3]),max(a[5],a[7]));
		return ((mn<=x&&x<=mx) & (mn2<=y&&y<=mx2));
	}
	else{
		int mn = min(min(b[0]+b[1],b[2]+b[3]),min(b[4]+b[5],b[6]+b[7]));
		int mx = max(max(b[0]+b[1],b[2]+b[3]),max(b[4]+b[5],b[6]+b[7]));
		int mn2 = min(min(b[0]-b[1],b[2]-b[3]),min(b[4]-b[5],b[6]-b[7]));
		int mx2 = max(max(b[0]-b[1],b[2]-b[3]),max(b[4]-b[5],b[6]-b[7]));
		return ((mn<=x+y&x+y<=mx) & (mn2<=x-y&x-y<=mx2));
	}
}
int main(){
	rep(i,8) cin>>a[i];
	rep(i,8) cin>>b[i];
        int mn = min(min(a[0],a[2]),min(a[4],a[6]));
		int mx = max(max(a[0],a[2]),max(a[4],a[6]));
		int mn2 = min(min(a[1],a[3]),min(a[5],a[7]));
		int mx2 = max(max(a[1],a[3]),max(a[5],a[7]));
		for(int i=mn;i<=mx;i++)for(int j=mn2;j<=mx2;j++) if(in(i,j,1)){
		    puts("YES"); return 0;
		}
	rep(i,4){
		if(in(a[i*2],a[i*2+1],1)){
			puts("YES");
			return 0;
		}
		if(in(b[i*2],b[i*2+1],0)){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}