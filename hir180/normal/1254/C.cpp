#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 1000000007;

int n;
vector<pair<ll,int>>up,dw;
int upmx,dwmx;

int main(){
	cin >> n;
	int a = 1,b = 2;
	
	for(int i=3;i<=n;i++){
		cout << 2 << " " << a <<  " " << b << " " << i << endl;
		int x; cin >> x;
		cout << 1 << " " << a <<  " " << b << " " << i << endl;
		ll A; cin >> A;
		if(x == 1){
			//up
			if(up.empty()){
				up.pb(mp(A,i));
				upmx = 0;
			}
			else{
				int id = upmx;
				cout << 2 << " " << a << " " << up[id].sc << " " << i << endl;
				int y; cin >> y;
				if(y == 1){
					int pre = id; 
					for(int x=0;x<id;x++){
						bool bad = 0;
						if(x && up[x-1].fi >= A) bad = 1;
						if(up[x].fi <= A) bad = 1;
						if(bad == false) {pre = x; break;}
					}
					vector<pair<ll,int>>nw_up;
					for(int i=0;i<pre;i++) nw_up.pb(up[i]);
					nw_up.pb(mp(A,i));
					for(int i=pre;i<up.size();i++) nw_up.pb(up[i]);
					up = nw_up;
				}
				else if(y == -1){
					int pre = id;
					for(int x=up.size()-1;x>id;x--){
						bool bad = 0;
						if(x+1!=up.size() && up[x+1].fi >= A) bad = 1;
						if(up[x].fi <= A) bad = 1;
						if(bad == false) {pre = x; break;}
					}
					vector<pair<ll,int>>nw_up;
					for(int i=0;i<=pre;i++) nw_up.pb(up[i]);
					nw_up.pb(mp(A,i));
					for(int i=pre+1;i<up.size();i++) nw_up.pb(up[i]);
					up = nw_up;
				}
				pair<ll,int>X =  mp(0,0);
				rep(i,up.size()) if(X.fi < up[i].fi) {X = up[i]; upmx = i;}
			}
		}
		else{
			//dw
			if(dw.empty()){
				dw.pb(mp(A,i));
				dwmx = 0;
			}
			else{
				int id = dwmx;
				cout << 2 << " " << b << " " << dw[id].sc << " " << i << endl;
				int y; cin >> y;
				if(y == 1){
					int pre = id;
					for(int x=0;x<id;x++){
						bool bad = 0;
						if(x && dw[x-1].fi >= A) bad = 1;
						if(dw[x].fi <= A) bad = 1;
						if(bad == false) {pre = x; break;}
					}
					vector<pair<ll,int>>nw_up;
					for(int i=0;i<pre;i++) nw_up.pb(dw[i]);
					nw_up.pb(mp(A,i));
					for(int i=pre;i<dw.size();i++) nw_up.pb(dw[i]);
					dw = nw_up;
				}
				else if(y == -1){
					int pre = id;
					for(int x=dw.size()-1;x>id;x--){
						bool bad = 0;
						if(x+1!=dw.size() && dw[x+1].fi >= A) bad = 1;
						if(dw[x].fi <= A) bad = 1;
						if(bad == false) {pre = x; break;}
					}
					vector<pair<ll,int>>nw_up;
					for(int i=0;i<=pre;i++) nw_up.pb(dw[i]);
					nw_up.pb(mp(A,i));
					for(int i=pre+1;i<dw.size();i++) nw_up.pb(dw[i]);
					dw = nw_up;
				}
				pair<ll,int>X =  mp(0,0);
				rep(i,dw.size()) if(X.fi < dw[i].fi) {X = dw[i]; dwmx = i;}

			}
		}
	}
	cout << 0;
	cout << " " << 1;
	for(int i=0;i<dw.size();i++){
		cout << " " << dw[dw.size()-1-i].sc ;
	}
	cout << " " << 2;
	for(int i=0;i<up.size();i++){
		cout << " " << up[up.size()-1-i].sc;
	}
	cout << endl;
}