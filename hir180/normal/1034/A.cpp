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
bool bad[4005];
int a[300005],n;
int pp[560],nxt=0;
int cnt[560];
vector<int>hoge;
int main(){
	for(int i=2;i<=4000;i++){
		if(bad[i]) continue;
		pp[nxt++] = i;
		for(int j=2;i*j<=4000;j++) bad[i*j] = 1;
	}
	scanf("%d",&n);
	int g = 0;
	rep(i,n){
		scanf("%d",&a[i]);
		g = __gcd(g,a[i]);
	}
	sort(a,a+n);
	rep(i,n) a[i] /= g;
	rep(i,n){
		rep(j,nxt){
			if(a[i]%pp[j] == 0){
				cnt[j]++;
				while(a[i]%pp[j] == 0) a[i]/=pp[j];
			}
		}
		if(a[i] != 1) hoge.pb(a[i]);
	}
	SORT(hoge);
	int ans = 0;
	rep(i,nxt) ans = max(ans,cnt[i]);
	rep(i,hoge.size()){
		int a = POSU(hoge,hoge[i])-POSL(hoge,hoge[i]);
		ans = max(ans,a);
	}
	if(ans == 0) ans = n+1;
	cout<<n-ans<<endl;
}