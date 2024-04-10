#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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
int q;

int main(){
	scanf("%d",&q);
	while(q--){
		int b,w; scanf("%d%d",&b,&w);
		if(min(b,w)*3+1 < max(b,w)){
			puts("NO"); continue;
		}
		if(b < w){
			vector<P>vec;
			for(int i=1001;vec.size()<b;i+=2) vec.pb(mp(1000,i));
			set<P>vec2;
			for(int i=1002;vec2.size()<b-1;i+=2) vec2.insert(mp(1000,i));
			for(int i=0;i<vec.size() && vec2.size() < w;i++){
				int dx[4]={0,0,1,-1};
				int dy[4]={1,-1,0,0};
				rep(k,4){
					int nx = vec[i].fi+dx[k];
					int ny = vec[i].sc+dy[k];
					if(vec2.find(mp(nx,ny)) != vec2.end()) continue;
					vec2.insert(mp(nx,ny));
					if(vec2.size() == w) break;
				}
			}
			puts("YES");
			for(int i=0;i<vec.size();i++) cout<<vec[i].fi<<" "<<vec[i].sc<<endl;
			int cnt = 0;
			for(auto it:vec2){
				cout<<it.fi<<" "<<it.sc<<endl;
				cnt++;
				if(cnt == w) break;
			}
		}
		else{
			vector<P>vec;
			for(int i=1000;vec.size()<w;i+=2) vec.pb(mp(1000,i));
			set<P>vec2;
			for(int i=1001;vec2.size()<w-1;i+=2) vec2.insert(mp(1000,i));
			for(int i=0;i<vec.size() && vec2.size() < b;i++){
				int dx[4]={0,0,1,-1};
				int dy[4]={1,-1,0,0};
				rep(k,4){
					int nx = vec[i].fi+dx[k];
					int ny = vec[i].sc+dy[k];
					if(vec2.find(mp(nx,ny)) != vec2.end()) continue;
					vec2.insert(mp(nx,ny));
					if(vec2.size() == b) break;
				}
			}
			puts("YES");
			for(int i=0;i<vec.size();i++) cout<<vec[i].fi<<" "<<vec[i].sc<<endl;
			int cnt = 0;
			for(auto it:vec2){
				cout<<it.fi<<" "<<it.sc<<endl;
				cnt++;
				if(cnt == b) break;
			}
		}
	}
}