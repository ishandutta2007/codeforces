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
int n,m,p;
int magic;
struct Boyer_Moore{
	int id[8],cnt[8];
	Boyer_Moore(){
		rep(i,8) id[i] = cnt[i] = 0;
	}
};
void init(Boyer_Moore &a){
	rep(i,8) a.id[i] = a.cnt[i] = 0;
}
Boyer_Moore merge(Boyer_Moore a,Boyer_Moore b){
	Boyer_Moore ret = a;
	for(int i=0;i<magic;i++){
		if(b.cnt[i] == 0) continue;
		bool en = false;
		for(int j=0;j<magic;j++){
			if(ret.id[j] == b.id[i]){
				ret.cnt[j] += b.cnt[i];
				en = true; break;
			}
		}
		if(en) continue;
		bool big = true;
		for(int j=0;j<magic;j++){
			if(ret.cnt[j] < b.cnt[i]) big = false;
		}
		if(big){
			for(int j=0;j<magic;j++){
				ret.cnt[j] -= b.cnt[i];
			}
			continue;
		}
		int mn = INF;
		for(int j=0;j<magic;j++){
			mn = min(mn,ret.cnt[j]);
		}
		for(int j=0;j<magic;j++){
			ret.cnt[j] -= mn;
		}
		for(int j=0;j<magic;j++){
			if(ret.cnt[j]==0){
				assert(b.cnt[i]-mn > 0);
				ret.cnt[j] = b.cnt[i]-mn;
				ret.id[j] = b.id[i];
				break;
			}
		}
	}
	return ret;
}
Boyer_Moore seg[(1<<19)],emp;
int flag[(1<<19)];
void push(int k,int l,int r){
	flag[k*2+1] = flag[k];
	flag[k*2+2] = flag[k];
	init(seg[k*2+1]); seg[k*2+1].id[0] = flag[k]; seg[k*2+1].cnt[0] = (r-l+1)/2;
	init(seg[k*2+2]); seg[k*2+2].id[0] = flag[k]; seg[k*2+2].cnt[0] = (r-l+1)/2;
	flag[k] = 0;
}
Boyer_Moore update(int a,int b,int k,int l,int r,int x){
	if(r<a || b<l) return seg[k];
	if(a<=l && r<=b){
		init(seg[k]);
		seg[k].id[0] = x;
		seg[k].cnt[0] = r-l+1;
		flag[k] = x;
		return seg[k];
	}
	if(flag[k]) push(k,l,r);
	return seg[k] = merge(update(a,b,k*2+1,l,(l+r)/2,x),update(a,b,k*2+2,(l+r)/2+1,r,x));
}
Boyer_Moore query(int a,int b,int k,int l,int r){
	if(r<a || b<l) return emp;
	if(a<=l && r<=b){
		return seg[k];
	}
	if(flag[k]) push(k,l,r);
	return merge(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2+1,r));
}

int main(){
    init(emp);
	scanf("%d%d%d",&n,&m,&p);
	magic = 100/p;
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		update(i,i,0,0,(1<<18)-1,a);
	}
	for(int i=1;i<=m;i++){ 
		int a; scanf("%d",&a);
		if(a == 1){
			int l,r,id; scanf("%d%d%d",&l,&r,&id);
			update(l,r,0,0,(1<<18)-1,id);
		}
		else{
			int l,r; scanf("%d%d",&l,&r);
			Boyer_Moore ans = query(l,r,0,0,(1<<18)-1);
			vector<int>vec;
			for(int i=0;i<magic;i++) if(ans.id[i]>0) vec.pb(ans.id[i]);
			printf("%d",vec.size());
			for(int i=0;i<vec.size();i++) printf(" %d",vec[i]);
			puts("");
		}
	}
}