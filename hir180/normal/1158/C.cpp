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


class segtree
{
public:
	ll s;
	P seg[(1<<20)];
	int lazy[(1<<20)];
	void init(int n){
		for(int i=0;;i++){
			if((1<<i) >= n+5){
				s = (1<<i);
				for(int j=s-1;j<2*s;j++){
					seg[j] = mp(0,j-s+1);
				}
				for(int j=s-2;j>=0;j--){
					seg[j] = seg[j*2+1];
				}
				for(int j=0;j<2*s;j++){
					lazy[j] = 0;
				}
				return;
			}
		}
	}
	void lazy_evaluate(int k)
	{
		if(k*2+2>=s*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2].fi+=lazy[k];
		seg[k*2+1].fi+=lazy[k];
		lazy[k]=0;
	}
	P update(int beg,int end,int idx,int lb,int ub,int num)
	{
		if(ub<beg||end<lb)
		{
			return seg[idx];
		}
		if(beg<=lb&&ub<=end)
		{
			lazy[idx]+=num;
			seg[idx].fi+=num;
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return seg[idx]=min(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	P query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return mp(INF,INF);
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return min(query(beg,end,idx*2+1,lb,(lb+ub)/2),query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
	}
	P update(int beg,int end,int num){
		return update(beg,end,0,0,s-1,num);
	}
	P query(int beg,int end){
		return query(beg,end,0,0,s-1);
	}
}kaede;

int q;
int n;
int p[500005];
vector<P>go[500005];
int ans[500005];
int main(){
	scanf("%d",&q);
	rep(r,q){
		scanf("%d",&n);
		kaede.init(n+2);
		for(int i=0;i<n;i++){
		    	scanf("%d",&p[i]); p[i]--;
			go[i].clear();
		}
		for(int i=0;i<n;i++){
			if(p[i] == -2) continue;
			if(p[i] != n){
				go[p[i]].push_back(mp(i,i));
				kaede.update(i,i,1); //cout << p[i] << " " <<  i << " " << i << endl;
			}
			if(p[i] > i+1){
				go[i].push_back(mp(i+1,p[i]-1));
				kaede.update(i+1,p[i]-1,1);// cout << i+1 << " " << p[i]-1 << endl;
			}
		}
		//cout << kaede.query(2,2).fi << " " << kaede.query(2,2).sc << endl;
		int cnt = 0;
		while(cnt < n){
			P p = kaede.query(0,n-1);
			if(p.fi != 0) break;
			ans[p.sc] = n-cnt;
			cnt++;
			for(int x=0;x<go[p.sc].size();x++){
				int L = go[p.sc][x].fi;
				int R = go[p.sc][x].sc;
				kaede.update(L,R,-1);
			}
			kaede.update(p.sc,p.sc,INF/10);
		}
		if(cnt != n){
			puts("-1");
		}
		else{
			for(int i=0;i<n;i++) printf("%d ",ans[i]);
			puts("");
		}
	}
}