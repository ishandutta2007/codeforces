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
int G[31]={0,1,
2,
1,
4,
3,
2,
1,
5,
6,
2,
1,
8,
7,
5,
9,
8,
7,
3,
4,
7,
4,
2,
1,
10,
9,
3,
6,
11,
12,
14};
int X,zan;
set<ll>S;
int main(){
	int n; cin>>n; zan = n;
	for(int i=2;i*i<=n;i++){
		if(S.find(1LL*i) != S.end()) continue;
		ll v = i; int c = 1; S.insert(v);
		while(v*i <= 1LL*n){
			v *= i; c++; S.insert(v);
		}
		X ^= G[c]; zan-=c;
	}
	X^=(zan%2);
	cout<<(X?"Vasya":"Petya")<<endl;
}