#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
int n,m;
int a[2005],to[2005];
int w;
bool used[2005];
//reactive
int main(){
	cin>>n>>m;
	repn(i,2*n){
		cin>>a[i];
	}
	rep(i,m){
		int x,y; cin>>x>>y;
		to[x] = y;
		to[y] = x;
	}
	cin>>w;
	if(w == 1){
		int zan = n;
		while(zan--){
			P mx = mp(-1,-1);
			for(int i=1;i<=2*n;i++){
				if(!used[i] && to[i]){
					mx = max(mx,mp(a[i],i));
				}
			}
			if(mx.sc != -1){
				cout<<mx.sc<<endl; used[mx.sc] = 1;
				int a; cin>>a; used[a] = 1; continue;
			}
			for(int i=1;i<=2*n;i++){
				if(!used[i]){
					mx = max(mx,mp(a[i],i));
				}
			}
			if(mx.sc != -1){
				cout<<mx.sc<<endl; used[mx.sc] = 1;
				int a; cin>>a; used[a] = 1; continue;
			}
		}
	}
	else{
		int zan = n;
		while(zan--){
			int aa; cin>>aa;
			used[aa] = 1;
			if(to[aa] && !used[to[aa]]){
				cout<<to[aa]<<endl;
				used[to[aa]] = 1;
				continue;
			}
			P mx = mp(-1,-1);
			for(int i=1;i<=2*n;i++){
				if(!used[i] && to[i]){
					mx = max(mx,mp(a[i],i));
				}
			}
			if(mx.sc != -1){
				cout<<mx.sc<<endl; used[mx.sc] = 1; continue;
			}
			for(int i=1;i<=2*n;i++){
				if(!used[i]){
					mx = max(mx,mp(a[i],i));
				}
			}
			if(mx.sc != -1){
				cout<<mx.sc<<endl; used[mx.sc] = 1; continue;
			}
		}
	}
}