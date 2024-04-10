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
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
vector<int>F;
vector<int>sx,sv;
void go(int n){
	if(n == 0) return;
	int t;
	for(int i=19;i>=0;i--){
		if(n >= (1<<i)){
			t = i; break;
		}
	}
	int sum = (1LL<<(t+1))-1;
	for(int i=n;i>=sum-n;i--){
		F.pb(sum-i);
	}
	go(sum-n-1);
}
int main(){
    int n; cin>>n;
	if(n%2 == 1) puts("NO");
	else{
		go(n);
		reverse(F.begin(),F.end());
		puts("YES");
		rep(i,n) printf("%d%c",F[i],(i==n-1?'\n':' '));
	}
	
	if(n<=5) puts("NO");
	else{
		if(n%2 == 1){
		    puts("YES");
			sx.pb(3); sx.pb(6); sx.pb(2); sx.pb(5); sx.pb(1); sx.pb(7); sx.pb(4);
			for(int i=8;i<=n;i+=2){
				sx.pb(i+1);
				sx.pb(i);
			}
			rep(i,n) printf("%d%c",sx[i],(i==n-1?'\n':' '));
			rep(i,n) if( ((1+i)&sx[i]) == 0) assert(0);
		}
		else{
			sx.pb(3); sx.pb(6); sx.pb(2); sx.pb(5); sx.pb(1); sx.pb(4);
			bool en = 0;
			for(int i=3;i<=17;i++){
				if(n == (1<<i)){
					puts("NO"); en = 1;
				}
			}
			if(!en){
			    puts("YES");
				int nxt = 3;
				int cur = 6;
				while(cur<n){
    				if(cur+2 == (1<<nxt)){
    					sx.pb(cur+3);
    					sx.pb(cur+4);
    					sx.pb(cur+1);
    					sx.pb(cur+2);
    					cur+=4;
    					nxt++;
    				}
    				else{
    					sx.pb(cur+2);
    					sx.pb(cur+1);
    					cur+=2;
    				}
				}
				rep(i,n) printf("%d%c",sx[i],(i==n-1?'\n':' '));
				rep(i,n) if( ((1+i)&sx[i]) == 0) assert(0);
			}
		}
	}
}