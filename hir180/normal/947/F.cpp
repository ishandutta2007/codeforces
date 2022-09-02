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
priority_queue<ll,vector<ll>,greater<ll> >que;
int n;
vector<P>edge; vector<int>G[10005],G2[10005];
bool used[100050000];
int cnt[10005],cnt2[10005];
void brute(){
	vector<int>vec;
	for(int i=0;i<n;i++) vec.pb(i);
	do{
		rep(i,edge.size()){
			int x = edge[i].fi,y = edge[i].sc;
			if(used[vec[x]*n+vec[y]]) goto nxt;
		}
		puts("Yes");
		rep(i,vec.size()) printf("%d ",vec[i]+n+1);
		puts(""); return; nxt:;
	}while(next_permutation(vec.begin(),vec.end()));
	puts("No");
}
double beg;
bool usedd[10005]={};
void omikuji(){
	vector<int>vec;
	for(int i=0;i<n;i++) vec.pb(i);
	P p = mp(-1,-1);
	for(int i=0;i<n;i++) p = max(p,mp(cnt[i],i));
	if(p.fi == n-1){
		puts("No"); return;
	}
	vector<int>nt;
	for(int i=0;i<G[p.sc].size();i++){
		usedd[G[p.sc][i]] = 1;
	}
	for(int i=0;i<n;i++) if(!usedd[i] && i != p.sc) nt.pb(i);
	vector<int>leaf;
	for(int i=0;i<n;i++) if(cnt2[i] == 1) leaf.pb(i);
	srand((unsigned)time(NULL));
	assert(leaf.size() && nt.size());
	while(clock()-beg <= 3.9*CLOCKS_PER_SEC){
		int L = abs(rand());
		int x = leaf[L%leaf.size()];
		L = abs(rand());
		int y = nt[L%nt.size()];
		//vec[p,sc] = x
		//vec[y] = G2[x][0]
		random_shuffle(vec.begin(),vec.end());
		if(vec[p.sc] != x){
			for(int i=0;i<n;i++){
				if(vec[i] == x){
					swap(vec[i],vec[p.sc]);
					break;
				}
			}
		}
		if(vec[y] != G2[x][0]){
			for(int i=0;i<n;i++){
				if(vec[i] == G2[x][0]){
					swap(vec[i],vec[y]);
					break;
				}
			}
		}
		assert(vec[p.sc] == x && vec[y] == G2[x][0]);
		rep(i,edge.size()){
			int x = edge[i].fi,y = edge[i].sc;
			if(used[vec[x]*n+vec[y]]) goto nxt2;
		}
		puts("Yes");
		rep(i,vec.size()) printf("%d ",vec[i]+n+1);
		puts(""); return; nxt2:;
	}
	puts("No");
}
void omikuji2(){
	vector<int>vec;
	for(int i=0;i<n;i++) vec.pb(i);
	P p = mp(-1,-1);
	for(int i=0;i<n;i++) p = max(p,mp(cnt2[i],i));
	if(p.fi == n-1){
		puts("No"); return;
	}
	vector<int>nt;
	for(int i=0;i<G2[p.sc].size();i++){
		usedd[G2[p.sc][i]] = 1;
	}
	for(int i=0;i<n;i++) if(!usedd[i] && i != p.sc) nt.pb(i);
	vector<int>leaf;
	for(int i=0;i<n;i++) if(cnt[i] == 1) leaf.pb(i);
	srand((unsigned)time(NULL));
	assert(leaf.size() && nt.size());
	while(clock()-beg <= 3.9*CLOCKS_PER_SEC){
		int L = abs(rand());
		int x = leaf[L%leaf.size()];
		L = abs(rand());
		int y = nt[L%nt.size()];
		//vec[x] = p.sc
		//vec[G[x][0]] = y
		random_shuffle(vec.begin(),vec.end());
		if(vec[x] != p.sc){
			for(int i=0;i<n;i++){
				if(vec[i] == p.sc){
					swap(vec[i],vec[x]);
					break;
				}
			}
		}
		if(vec[G[x][0]] != y){
			for(int i=0;i<n;i++){
				if(vec[i] == y){
					swap(vec[i],vec[G[x][0]]);
					break;
				}
			}
		}
		assert(vec[x] == p.sc && vec[G[x][0]] == y);
		rep(i,edge.size()){
			int x = edge[i].fi,y = edge[i].sc;
			if(used[vec[x]*n+vec[y]]) goto nxt2;
		}
		puts("Yes");
		rep(i,vec.size()) printf("%d ",vec[i]+n+1);
		puts(""); return; nxt2:;
	}
	puts("No");
}
int main(){
	beg = clock();
	cin>>n;
	P p = mp(-1,-1);
	rep(i,n-1){
		int a,b;
		cin>>a>>b; a--; b--;
		edge.pb(mp(a,b)); cnt[a]++; cnt[b]++;
		G[a].pb(b);
		G[b].pb(a);
	}
	rep(i,n-1){
		int a,b;
		cin>>a>>b; //a--; b--;
		a-=n+1; b-=n+1;
		used[a*n+b] = used[b*n+a] = 1; cnt2[a]++; cnt2[b]++;
		G2[a].pb(b);
		G2[b].pb(a);
	}
	rep(i,n) p = max(p,mp(cnt[i],i));
	rep(i,n) p = max(p,mp(cnt2[i],n+i));
	if(n<=10){
		brute(); return 0;
	}
	else{
		if(p.sc<n) omikuji(); else omikuji2(); return 0;
	}
}