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
int n,q;
int a[300005];
vector<int>pos[300005];
vector<P2 >query;
vector<int>seg[(1<<20)+5];
P len[(1<<20)+5];
void make(int a,int x){
	a += (1<<19)-1;
	seg[a].pb(x);
}
void make2(){
	for(int i=(1<<19)-1;i<(1<<20);i++) len[i] = mp(i-(1<<19)+1,i-(1<<19)+1);
	for(int i=(1<<19)-2;i>=0;i--){
		len[i] = mp(len[i*2+1].fi,len[i*2+2].sc);
		for(int j=0;j<seg[i*2+1].size();j++){
			int s = seg[i*2+1][j];
			int L = lower_bound(pos[s].begin(),pos[s].end(),len[i].fi)-pos[s].begin();
			int R = L+(len[i].sc-len[i].fi+1)/5;
			if(R<pos[s].size() && pos[s][R]<=len[i].sc) seg[i].pb(s);
		}
		for(int j=0;j<seg[i*2+2].size();j++){
			int s = seg[i*2+2][j];
			int L = lower_bound(pos[s].begin(),pos[s].end(),len[i].fi)-pos[s].begin();
			int R = L+(len[i].sc-len[i].fi+1)/5;
			if(R<pos[s].size() && pos[s][R]<=len[i].sc) seg[i].pb(s);
		}
		sort(seg[i].begin(),seg[i].end()); seg[i].erase(unique(seg[i].begin(),seg[i].end()),seg[i].end());
	}
}int nxt[300005],ans[300005];
void go(int a,int b,int k,int l,int r,P2 p){
	if(r<a || b<l) return ;
	if(a<=l && r<=b){
		for(int i=0;i<seg[k].size();i++){
			while(nxt[seg[k][i]] != pos[seg[k][i]].size() && pos[seg[k][i]][nxt[seg[k][i]]] < p.fi.fi) nxt[seg[k][i]]++;
			if(nxt[seg[k][i]] == pos[seg[k][i]].size() ) continue;
			int e = nxt[seg[k][i]]-1+(p.fi.sc-p.fi.fi+p.sc.fi+1)/p.sc.fi;
			if(e < pos[seg[k][i]].size() && pos[seg[k][i]][e] <= p.fi.sc){
				ans[p.sc.sc] = min(ans[p.sc.sc],seg[k][i]);
			}
		}
		return;
	}
	go(a,b,k*2+1,l,(l+r)/2,p);
	go(a,b,k*2+2,(l+r)/2+1,r,p);
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		pos[a[i]].pb(i);
		make(i,a[i]);
	}
	make2();
	for(int i=0;i<q;i++){
		int l,r,k; scanf("%d%d%d",&l,&r,&k); l--; r--;
		query.pb(mp(mp(l,r),mp(k,i))); ans[i] = INF;
	}
	sort(query.begin(),query.end());
	for(int i=0;i<query.size();i++){
		go(query[i].fi.fi,query[i].fi.sc,0,0,(1<<19)-1,query[i]);
	}
	for(int i=0;i<q;i++){
		if(ans[i] == INF) ans[i] = -1;
		printf("%d\n",ans[i]);
	}
}