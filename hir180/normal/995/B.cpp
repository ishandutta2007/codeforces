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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<P>vec;
int n,a[205],cnt[205];
int b[205],c[205],pos[205];
int main(){
	cin>>n;
	for(int i=1;i<=2*n;i++){
		cin>>a[i];
		if(cnt[a[i]] == 0){
			b[i] = a[i]*2-1;
		}
		else{
			b[i] = a[i]*2;
		}
		cnt[a[i]]+=i;
	}
	for(int i=1;i<=n;i++) vec.pb(mp(cnt[i],i));
	SORT(vec);
	for(int i=0;i<n;i++){
		c[i*2+1] = vec[i].sc*2-1;
		c[i*2+2] = vec[i].sc*2;
	}
	for(int i=1;i<=2*n;i++) pos[c[i]] = i;
	int ans = 0;
	for(int i=1;i<=2*n;i++) for(int j=i+1;j<=2*n;j++){
		if(pos[b[i]] > pos[b[j]]) ans++;
	}
	cout<<ans<<endl;
}