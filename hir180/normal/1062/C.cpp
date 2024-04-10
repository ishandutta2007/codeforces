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
int n,q;
ll bin[100005];
vector<int>pos;
string str;
int main(){
	cin>>n>>q>>str;
	for(int i=0;i<n;i++){
		if(str[i] == '1') pos.pb(i+1);
	}
	bin[0] = 1;
	for(int i=1;i<100005;i++) bin[i] = bin[i-1]*2LL%mod;
	rep(i,q){
		int l,r; scanf("%d%d",&l,&r);
		int d = POSU(pos,r)-POSL(pos,l);
		printf("%lld\n",(bin[d]+mod-1)%mod*bin[r-l+1-d]%mod);
	}
}