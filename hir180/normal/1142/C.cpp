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

//
int n;
vector<P>_a,a;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b; scanf("%d%d",&a,&b);
		_a.pb(mp(a,b));
	}
	SORT(_a);
	rep(i,_a.size()){
		if(i == _a.size()-1 || _a[i].fi != _a[i+1].fi){
			a.pb(_a[i]);
			//cout << _a[i].fi << " " << _a[i].sc << endl;
		}
	}
	deque<P>deq;
	for(int i=0;i<a.size();i++){
		while(deq.size() >= 2){
			ll p1 = deq[deq.size()-2].fi, q1 = deq[deq.size()-2].sc;
			ll p2 = deq[deq.size()-1].fi, q2 = deq[deq.size()-1].sc;
			ll p3 = (ll)a[i].fi, q3 = (ll)a[i].sc;
			ll up1 = p1*p1-p2*p2+q2-q1; ll dw1 = 2LL*p1-2LL*p2;
			ll up2 = p2*p2-p3*p3+q3-q2; ll dw2 = 2LL*p2-2LL*p3;
			//up1 / dw1 >= up2 / dw2 -> pop
			if(dw1 < 0){
				up1 *= -1;
				dw1 *= -1;
			}
			if(dw2 < 0){
				up2 *= -1;
				dw2 *= -1;
			}
			if(up1*dw2 >= up2*dw1){
				deq.pop_back();
			}
			else{
				break;
			}
		}
		deq.push_back(a[i]);
	}
	cout << deq.size()-1 << endl;
	return 0;
}