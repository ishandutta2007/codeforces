#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const ll mod = 1000000007;

int n,q;
bool s[2][100005];
int sum;
int calc(int a,int b){
	if(s[a][b] == false) return 0;
	for(int i=b-1;i<=b+1;i++) if(1<=i&&i<=n&&s[1-a][i]) return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&q);
	rep(i,q){
		int a,b; scanf("%d%d",&a,&b); a--;
		rep(a,2) for(int i=b-1;i<=b+1;i++) if(1<=i&&i<=n) sum -= calc(a,i);
		s[a][b] ^= 1;
		rep(a,2) for(int i=b-1;i<=b+1;i++) if(1<=i&&i<=n) sum += calc(a,i);
		puts(sum?"No":"Yes");
	}
}