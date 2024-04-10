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
int main(){
	string s;cin>>s;
	ll ans = 0,cur = 0,pre = 0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='a'){
			ans += pre*2+cur; ans %= mod;
			pre = pre*2+cur; pre %= mod; cur = 0;
		}
		else{
			cur++;
		}
	}
	cout<<ans%mod<<endl;
}