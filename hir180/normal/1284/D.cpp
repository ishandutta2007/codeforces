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

vector<int>za;
int n;
int a[2][100005],b[2][100005];
vector<P>query[400005];

struct BIT
{
	int bit[400005];
	void init(){ memset(bit,0,sizeof(bit)); }
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		for(int s=i;s<400005;s+=f(s)) bit[s]+=x;
	}
	int sum(int i)
	{
		int res=0;
		for(int s=i;s>0;s-=f(s)) res+=bit[s];
		return res;
	}
}bit[2];

int main(){
	scanf("%d",&n);
	rep(i,n){
		rep(j,2){
			scanf("%d%d",&a[j][i],&b[j][i]);
			za.pb(a[j][i]);
			za.pb(b[j][i]);
		}
	}
	SORT(za); ERASE(za);
	
	rep(i,n){
		rep(j,2){
			a[j][i] = POSL(za,a[j][i]);
			b[j][i] = POSL(za,b[j][i]);
		}
	}
	
	rep(look,2){
		rep(i,2) bit[i].init();
		rep(i,za.size()) query[i].clear();
		rep(i,n){
			query[a[look][i]].pb(mp(0,i));
			query[b[look][i]].pb(mp(1,i));
		}
		rep(i,za.size()) SORT(query[i]);
		int cur = 0;
		rep(i,za.size()){
			rep(j,query[i].size()){
				int ty = query[i][j].fi;
				int id = query[i][j].sc;
				
				if(ty == 0){
					int check = bit[1].sum(a[1-look][id]);
					check += cur - bit[0].sum(b[1-look][id]+1);
					//cout << check << " " << cur << " " << look << " " << ty << " "<< id << endl;
					if(check != cur){
						puts("NO"); return 0;
					}
				}
				else{
					bit[0].add(a[1-look][id]+1,1);
					bit[1].add(b[1-look][id]+1,1);
					cur++;
				}
			}
		}
	}
	
	puts("YES");
}