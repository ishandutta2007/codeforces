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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int vec[1000005];
map<ll,int>M;
int main(){
	int n; cin >> n;
	for(int i=2;i<=1000000;i++){
		if(vec[i]) continue;
		for(int j=i;j<=1000000;j+=i) vec[j] = i;
	}
	for(int i=1;i<=1000000;i++){
		M[1LL*i*i*i] = i;
	}
	rep(i,n){
		ll a,b; scanf("%lld%lld",&a,&b);
		ll c = a*b; bool bad = 0;
		if(M.find(c) == M.end()){
			bad = 1;
		}
		else{
			int x = M[c];
			while(x!=1){
				int y = vec[x];
				{
					int A=0,B=0;
					while(a%y == 0){
						a/=y;A++;
					}
					while(b%y == 0){
						b/=y;B++;
					}
					while(x%y==0) x/=y;
				
				if(A+B > 0){
					if( (A+B)%3 == 0 && min(A,B)*2 >= max(A,B) );
					else bad = 1;
				}
			}}
		}
		puts(bad?"No":"Yes");
	}
}