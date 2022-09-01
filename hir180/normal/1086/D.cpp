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
int n,q;
char s[200005];
struct RMQ{
	#define ss (1<<19)
	int seg[ss];
	void init(){memset(seg,0,sizeof(seg));}
	void update(int k,int a){
		k+=ss/2-1; seg[k]+=a;
		while(k>0){
			k=(k-1)/2;
			seg[k]=(seg[k*2+1]+seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return 0;
		if(a<=l && r<=b) return seg[k];
		else{
			int vl=query(a,b,k*2+1,l,(l+r)/2);
			int vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return (vl+vr);
		}
	}
}C[3];
set<int>cur[3];
int calc(){
	int ans = 0;
	for(int i=0;i<3;i++){
		P a = mp(INF,INF-1),b = mp(INF,INF-1);
		int q = (cur[(i+1)%3].size()?(*cur[(i+1)%3].begin()):n);
		int r = (cur[(i+2)%3].size()?(*cur[(i+2)%3].begin()):n);
		if(q < r) a = mp(q,r-1);
		
		int qq = -1;
		int rr = -1;
		if(cur[(i+1)%3].size()){
			set<int>::iterator it = cur[(i+1)%3].end();
			it--;
			qq = *it;
		}
		if(cur[(i+2)%3].size()){
			set<int>::iterator it = cur[(i+2)%3].end();
			it--;
			rr = *it;
		}
		if(qq > rr) b = mp(rr+1,qq);
		int L = max(a.fi,b.fi);
		int R = min(a.sc,b.sc);
		if(L <= R){
			ans += C[i].query(min(a.fi,b.fi),max(a.sc,b.sc),0,0,(1<<18)-1);
		}
		else{
			if(a.fi <= a.sc) ans += C[i].query(a.fi,a.sc,0,0,(1<<18)-1);
			if(b.fi <= b.sc) ans += C[i].query(b.fi,b.sc,0,0,(1<<18)-1);
		}
		//cout<<ans<<"N"<<endl;
	}
	return n-ans;
}
int main(){
	scanf("%d%d%s",&n,&q,&s);
	rep(i,3) C[i].init();
	map<char,int>M;
	M['R'] = 0;
	M['P'] = 1;
	M['S'] = 2;
	for(int i=0;i<n;i++){
		int k = M[s[i]];
		C[k].update(i,1);
		cur[k].insert(i);
	}
	
	int ans = calc();
	printf("%d\n",ans);
	
	for(int i=0;i<q;i++){
		int a; char ch; scanf("%d %c",&a,&ch); 
		a--;
		C[M[s[a]]].update(a,-1);
		cur[M[s[a]]].erase(cur[M[s[a]]].find(a));
		s[a] = ch;
		C[M[s[a]]].update(a,1);
		cur[M[s[a]]].insert(a);
		int ans = calc();
		printf("%d\n",ans);
	}
}