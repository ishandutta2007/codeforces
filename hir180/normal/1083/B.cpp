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
int k,n;
string s,t;
ll ans;
int main(){
	cin>>n>>k>>s>>t;
	ll cura = 0, curb = 0;
	for(int i=0;i<n;i++){
		cura = cura*2LL+(s[i]-'a');
		curb = curb*2LL+(t[i]-'a');
		ans += min(1LL*k,curb-cura+1LL);
		if(curb-cura+1LL>1e18){
			ans += 1LL*k*(n-1-i);
			break;
		}
		curb -= cura;
		cura = 0;
	}
	cout<<ans<<endl;
}