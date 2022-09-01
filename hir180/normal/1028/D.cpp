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
set<ll>sm,md,bg;
int n;
int main(){
	scanf("%d",&n);
	ll ans = 1;
	rep(i,n){
		char ch[10]; ll x; scanf(" %s%lld",&ch,&x);
		if(strlen(ch) == 3){
			bool in = 0;
			if(sm.size()){
				auto it = sm.rbegin();
				if(*it > x){
					sm.insert(x); in = 1;
				}
			}
			if(bg.size()){
				auto it = bg.begin();
				if(*it < x){
					bg.insert(x); in = 1;
				}
			}
			if(!in) md.insert(x);
		}
		else{
			if(sm.find(x) != sm.end()){
				auto it = sm.rbegin();
				if(*it != x){
					ans = 0;
				}
				while(md.size()){
					bg.insert(*md.begin());
					md.erase(md.begin());
				}
				sm.erase(sm.find(x));
			}
			else if(bg.find(x) != bg.end()){
				auto it = bg.begin();
				if(*it != x){
					ans = 0;
				}
				while(md.size()){
					sm.insert(*md.begin());
					md.erase(md.begin());
				}
				bg.erase(bg.find(x));
			}
			else{
				ans = ans*2LL%mod; //cout << ans << endl;
				while(md.size() && *md.begin() < x){
					sm.insert(*md.begin());
					md.erase(md.begin());
				}
				assert(*md.begin() == x);
				md.erase(md.begin());
				while(md.size()){
					bg.insert(*md.begin());
					md.erase(md.begin());
				}
			}
		}
	}
	ll sz = md.size()+1;
	ans = ans*sz%mod;
	cout << ans << endl;
}