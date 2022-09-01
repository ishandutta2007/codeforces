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
P2 p[200005];
P2 q[200005];
int a[200005][4],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) rep(j,4) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		if(i == 1){
			p[i] = mp(mp(a[i][0],a[i][1]),mp(a[i][2],a[i][3]));
		}
		else{
			p[i].fi.fi = max(p[i-1].fi.fi,a[i][0]);
			p[i].fi.sc = max(p[i-1].fi.sc,a[i][1]);
			p[i].sc.fi = min(p[i-1].sc.fi,a[i][2]);
			p[i].sc.sc = min(p[i-1].sc.sc,a[i][3]);
		}
	}
	for(int i=n;i>=1;i--){
		if(i == n){
			q[i] = mp(mp(a[i][0],a[i][1]),mp(a[i][2],a[i][3]));
		}
		else{
			q[i].fi.fi = max(q[i+1].fi.fi,a[i][0]);
			q[i].fi.sc = max(q[i+1].fi.sc,a[i][1]);
			q[i].sc.fi = min(q[i+1].sc.fi,a[i][2]);
			q[i].sc.sc = min(q[i+1].sc.sc,a[i][3]);
		}
	}
	for(int i=1;i<=n;i++){
		if(i == 1){
			if(q[2].fi.fi <= q[2].sc.fi && q[2].fi.sc <= q[2].sc.sc){
				cout << q[2].fi.fi << " " << q[2].fi.sc << endl;
				return 0;
			}
		}
		else if(i == n){
			if(p[n-1].fi.fi <= p[n-1].sc.fi && p[n-1].fi.sc <= p[n-1].sc.sc){
				cout << p[n-1].fi.fi << " " << p[n-1].fi.sc << endl;
				return 0;
			}
		}
		else{
			int aa = max(p[i-1].fi.fi,q[i+1].fi.fi);
			int bb = max(p[i-1].fi.sc,q[i+1].fi.sc);
			int cc = min(p[i-1].sc.fi,q[i+1].sc.fi);
			int dd = min(p[i-1].sc.sc,q[i+1].sc.sc);
			if(aa<=cc && bb<=dd){
				cout<<aa<<" "<<bb<<endl;
				return 0;
			}
		}
	}
}