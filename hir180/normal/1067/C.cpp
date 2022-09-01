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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int main(){
	int a; cin>>a;
	if(a<=10){
		for(int i=1;i<=a;i++) printf("1 %d\n",i);
		return 0;
	}
	int f = 2*a/3;
	for(int i=0;i<f;i++){
		for(int j=0;j<3;j++){
			if(i%2 == j%2){
				cout<<i<<" "<<j<<endl;a--;
				if(a==0) return 0;
			}
		}
	}
	rep(x,a) cout<<x<<" "<<4<<endl;
}