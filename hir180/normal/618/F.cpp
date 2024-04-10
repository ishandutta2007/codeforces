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
int n,a[1000005],b[1000005];
ll SA=0,SB=0;
vector<P>vec[1000005];
int main(){
	cin>>n;
	repn(i,n) scanf("%d",&a[i]),SA+=a[i];
	repn(i,n) scanf("%d",&b[i]),SB+=b[i];
	int C = 0;
	if(SA > SB){
		ll sum = 0;
		int cnt = 1;ll sum2 = 0;
		for(int i=0;i<=n;i++){
			if(i) sum += b[i];
			while(sum2 < sum){
				sum2 += a[cnt++];
			}
			ll S = sum2;
			vec[sum2-sum].pb(mp(cnt-1,i));
			C++;
			for(int j=cnt;j<=n;j++){
				S += a[j];
				if(S>sum+n) break;
				vec[S-sum].pb(mp(j,i));
				C++;
			}
			if(C > n+100) break;
		}
	}
	else{
		ll sum = 0;
		int cnt = 1;ll sum2 = 0;
		for(int i=0;i<=n;i++){
			if(i) sum += a[i];
			while(sum2 < sum){
				sum2 += b[cnt++];
			}
			ll S = sum2;
			vec[sum2-sum].pb(mp(i,cnt-1));
			C++;
			for(int j=cnt;j<=n;j++){
				S += b[j];
				if(S>sum+n) break;
				vec[S-sum].pb(mp(i,j));
				C++;
			}
			if(C > n+100) break;
		}
	}
	for(int i=1;i<=n;i++){
		if(vec[i].size() >= 2){
			int aa = vec[i][0].fi,bb = vec[i][0].sc;
			int c = vec[i][1].fi,d = vec[i][1].sc;
			ll S = 0,T = 0;
			for(int i=aa+1;i<=c;i++) S += a[i];
			for(int i=bb+1;i<=d;i++) T += b[i];
			assert(S == T);
			printf("%d\n",c-aa);
			for(int i=aa+1;i<=c;i++) printf("%d\n",i);
			printf("%d\n",d-bb);
			for(int i=bb+1;i<=d;i++) printf("%d\n",i);
			return 0;
		}
	}
	assert(vec[0].size() >= 2);
	assert(vec[0][0].fi==0);
	{
		
			int aa = vec[0][1].fi,bb = vec[0][1].sc;
			ll S = 0,T = 0;
			for(int i=1;i<=aa;i++) S += a[i];
			for(int i=1;i<=bb;i++) T += b[i];
			assert(S == T);
			printf("%d\n",aa);
			repn(i,aa) printf("%d\n",i);
			printf("%d\n",bb);
			repn(i,bb) printf("%d\n",i);
			return 0;
		
	}
}