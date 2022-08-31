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

int n,m,s[5005];
int L[5005],R[5005];
vector<int>cow[5005];
int cnt[5005];
pair<int,ll>ret;
int zan[5005];

pair<int,ll>mrg(pair<int,ll>a,pair<int,ll>b){
	if(a.fi < b.fi) return b;
	else if(a.fi > b.fi) return a;
	else{
		ll c = a.sc+b.sc;
		if(c < 0) c+=mod;
		if(c >= mod) c-=mod;
		return mp(a.fi,c);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	repn(i,n){
		scanf("%d",&s[i]); 
		cnt[s[i]]++;
	}
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		cow[a].pb(b);
	}
	repn(i,n) SORT(cow[i]);
	repn(i,n){
		rep(j,cow[i].size()) if(cow[i][j] <= cnt[i]) R[i]++;
	}
	//all right
	{
		int cnt = 0;
		ll way = 1;
		repn(j,n){
			if(L[j] == 0 && R[j] == 0);
			else if(L[j] == 0) { cnt++; way = way*R[j]%mod; }
			else if(R[j] == 0) { cnt++; way = way*L[j]%mod; }
			else{
				cnt += 2;
				way = way*min(L[j],R[j])%mod*(max(L[j],R[j])-1)%mod;
			}
		}
		ret = mrg(ret,mp(cnt,way));
	}
	repn(i,n){
		zan[s[i]]++;
		int k = POSL(cow[s[i]],zan[s[i]]);
		int kk = POSL(cow[s[i]],cnt[s[i]]-zan[s[i]]+1);
		if(kk < cow[s[i]].size() && cow[s[i]][kk] == cnt[s[i]]-zan[s[i]]+1) R[s[i]]--;
		if(k < cow[s[i]].size() && cow[s[i]][k] == zan[s[i]]){
			L[s[i]]++;
			int cnt = 0;
			ll way = 1;
			
			repn(j,n){
				if(j != s[i]){
					if(L[j] == 0 && R[j] == 0);
					else if(L[j] == 0) { cnt++; way = way*R[j]%mod; }
					else if(R[j] == 0) { cnt++; way = way*L[j]%mod; }
					else if(L[j] == 1 && R[j] == 1){ cnt++; way = way*2LL%mod; }
					else{
						cnt += 2;
						way = way*min(L[j],R[j])%mod*(max(L[j],R[j])-1)%mod;
					}
				}
				else{
					//L is decided
					if(R[j] >= L[j]){
						if(R[j] == 1) cnt++;
						else { cnt+= 2; way=way*(R[j]-1)%mod; }
					}
					else{
						if(R[j] == 0) cnt++;
						else { cnt+=2; way=way*R[j]%mod; }
					}
				}
			}
			ret = mrg(ret,mp(cnt,way));
		}
	}
	cout << ret.fi << " " << ret.sc << endl;
}