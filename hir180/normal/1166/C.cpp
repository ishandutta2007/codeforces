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

int n;
int a[200005];
vector<int>pos,neg;

int main(){
	cin>>n;
	rep(i,n){
		scanf("%d",&a[i]);
		if(a[i] > 0) pos.pb(a[i]);
		else neg.pb(-a[i]);
	}
	SORT(pos); SORT(neg);
	ll ans = 0;
	for(int i=0;i<pos.size();i++){
		int beg = POSU(pos,pos[i]);
		int en = POSU(pos,pos[i]*2);
		ans += en-beg;
	}
	for(int i=0;i<neg.size();i++){
		int beg = POSU(neg,neg[i]);
		int en = POSU(neg,neg[i]*2);
		ans += en-beg;
		int beg2 = POSL(pos,(neg[i]+1)/2);
		int en2 = POSU(pos,neg[i]*2);
		ans += en2-beg2;
	}
	cout<<ans<<endl;
}