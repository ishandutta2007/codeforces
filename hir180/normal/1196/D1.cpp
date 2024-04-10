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
int n,k;
vector<int>pos[3][3];
char s[200005];
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&k);
		scanf("%s",&s);
		rep(i,3) rep(j,3) pos[i][j].clear();
		rep(i,n){
			int id ;
			if(s[i] == 'R') id=0; else if(s[i] == 'G') id=1; else id =2;
			pos[i%3][id].pb(i);
		}
		int ans = INF;
		for(int i=0;i+k-1<n;i++){
		rep(b,3){int C = 0;
			for(int j=i%3,kk=b,ll=0;ll<3;ll++,j=(j+1)%3,kk=(kk+1)%3){
				
				for(int x=0;x<3;x++){
					if(kk == x) continue;
					C += POSU(pos[j][x],i+k-1)-POSL(pos[j][x],i);
				}
				//ans = min(ans,C);
			}ans = min(ans,C);}
		}
		printf("%d\n",ans);
	}
}