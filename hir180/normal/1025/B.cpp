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
bool ok[50005];
int n;
ll a[200005],b[200005],cur;
ll gcdd(ll a,ll b){
	if(a < b) swap(a,b);
	if(b == 0) return a;
	return gcdd(b,a%b);
}
int main(){
	cin>>n;
	rep(i,n){
		scanf("%lld%lld",&a[i],&b[i]);
		if(a[i] > b[i]) swap(a[i],b[i]);
	}
	ll cur = 0;
	rep(i,n){
		cur = gcdd(cur,a[i]*b[i]);
	}
	if(cur == 1){
		puts("-1");
	}
	else{
		for(ll i=2;i*i<=a[0];i++){
		    if(a[0]%i == 0){
		        if(cur%i == 0){ cout<<i<<endl; return 0;}
		        while(a[0]%i==0)a[0]/=i;
		    }
		}
		if(a[0] >= 2 && cur%a[0]==0){cout<<a[0]<<endl; return 0;}
		a[0] = b[0];
		for(ll i=2;i*i<=a[0];i++){
		    if(a[0]%i == 0){
		        if(cur%i == 0){ cout<<i<<endl; return 0;}
		        while(a[0]%i==0)a[0]/=i;
		    }
		}
		if(a[0] >= 2 && cur%a[0]==0){cout<<a[0]<<endl; return 0;}
	}
}