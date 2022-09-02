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
int n,a,b;
int main(){
	cin>>n>>a>>b;
	for(int i=0;i*a<=n;i++){
		int j = n-i*a;
		if(j%b != 0) continue;
		int A = i,B = j/b;
		int nxt = 1;
		rep(t,A){
			//[nxt,nxt+a-1]
			for(int i=nxt;i<=nxt+a-1;i++){
				if(i != nxt+a-1){
					printf("%d ",i+1);
				}
				else{
					printf("%d ",nxt);
				}
			}
			nxt += a;
		}
		rep(t,B){
			//[nxt,nxt+a-1]
			for(int i=nxt;i<=nxt+b-1;i++){
				if(i != nxt+b-1){
					printf("%d ",i+1);
				}
				else{
					printf("%d ",nxt);
				}
			}
			nxt += b;
		}
		puts("");
		return 0;
	}
	puts("-1");
}