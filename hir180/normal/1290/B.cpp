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

char s[200005];
vector<int>pos[26];
int n,q;

int main(){
	scanf("%s",&s);
	scanf("%d",&q);
	n = strlen(s);
	rep(i,n) pos[s[i]-'a'].pb(i);
	
	rep(i,q){
		int x,y; scanf("%d%d",&x,&y);
		x--; y--;
		if(x == y || s[x] != s[y]) puts("Yes");
		else{
			//type <= 2?
			int ex = 0;
			rep(k,26){
				ex += (POSU(pos[k],y)-POSL(pos[k],x)) > 0;
			}
			if(ex <= 2) puts("No");
			else puts("Yes");
		}
	}
}