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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
string s;

int NN,k;
int ran[200005];
int tmp[200005];
int sa[200005];

bool compare_sa(int i,int j)
{
	if(ran[i] != ran[j]) return ran[i] < ran[j];
	else
	{
		int ri = i+k<=NN ? ran[i+k]: -1;
		int rj = j+k<=NN ? ran[j+k]: -1;
		
		return ri < rj;
	}
}

void construct_sa(string S)
{
	NN = S.size();
	for(int i=0;i<=NN;i++)
	{
		sa[i] = i;
		ran[i] = i<NN?S[i]:-1;
	}
	
	for(k=1;k<=NN;k*=2)
	{
		sort(sa,sa+NN+1,compare_sa);
		
		tmp[sa[0]] = 0;
		for(int i=1;i<=NN;i++)
		{
			tmp[sa[i]] = tmp[sa[i-1]] + compare_sa(sa[i-1],sa[i]);
		}
		for(int i=0;i<=NN;i++)
		{
			ran[i] = tmp[i];
		}
	}
}
int lcp[200005];
void construct_lcp(string S)
{
	int n = S.size();
	for(int i=0;i<=n;i++) ran[sa[i]] = i;
	
	int h = 0;
	lcp[0] = 0;
	
	for(int i=0;i<n;i++)
	{
		int j = sa[ran[i]-1];
		
		if(h) h--;
		for(;j+h<n && i+h<n;h++)
		{
			if(S[j+h] != S[i+h]) break;
		}
		lcp[ran[i]-1] = h;
	}
}

int mn[200005][20];
int num[200005];
void update(int k,int a){
	mn[k][0] = a;
}
int calc(int l,int r){
	assert(l != r);
	if(l > r) swap(l,r);
	//[l,r-1]
	int a = num[r-l];
	return min(mn[l][a],mn[r-(1<<a)][a]);
}

struct SegmentTree{
	vector<int>seg;
	int sz;
	
	SegmentTree(vector<int>array)
	{
		sz = 1;
		while(sz < array.size()) sz <<= 1;
		seg.resize(2 * sz - 1);
		
		for(int k = 0; k < array.size(); k++) {
			seg[k + sz - 1] = array[k];
		}
		for(int k = sz - 2; k >= 0; k--) {
			seg[k] = min(seg[k*2+1],seg[k*2+2]);
		}
	}
	inline void update(int k,int val){
	    k += sz-1; seg[k] = val;
	    while(k){
	        k = (k-1)/2;
	        seg[k] = min(seg[k*2+1],seg[k*2+2]);
	    }
	}
	inline int query(int a, int b, int k, int l, int r)
	{
		if(a >= r || b <= l) {
			return INF;
		}else if(a <= l && r <= b) {
			return seg[k];
		} else {
			return (min(query(a, b, 2 * k + 1, l, (l + r) >> 1), query(a, b , 2 * k + 2, (l + r) >> 1, r)));
		}
	}
	inline int query(int a,int b) { return query(a,b,0,0,sz); }
};

int main(){
    ios::sync_with_stdio(false);
	for(int i=1;i<200005;i++){
		rep(j,30){
			if((1<<j) <= i && (2<<j) >= i){
				num[i] = j; break;
			}
		}
	}
	cin >> n >> s;
	construct_sa(s);
	construct_lcp(s);
	rep(i,200005)rep(j,20) mn[i][j] = INF;
	vector<int>SA;
	for(int i=0;i<s.size();i++){
		update(i,lcp[i]);
	}
	for(int i=0;i<=n;i++) SA.pb(sa[i]);
	SegmentTree kaede(SA);
	rep(j,19)rep(i,200005){
		if(i+(1<<j) > 200000) mn[i][j+1] = mn[i][j];
		else mn[i][j+1] = min(mn[i][j],mn[i+(1<<j)][j]);
	}
	int ret = 0;
	rep(i,n){
		int pre = i-1;
		int r = i;
		int ans = 0;
		kaede.update(ran[i],INF);
		while(1){
			int len = n-1-pre;
			int num = len / (r-pre);
			int lb = 0,ub = num+1;
			while(ub-lb > 1){
				int mid = (lb+ub)/2;
				int x = ran[pre+1];
				int y = ran[r+1];
				if(calc(x,y) >= (r-pre)*(mid-1)) lb = mid;
				else ub = mid;
			}
			ans += lb;
			r = pre + (r-pre)*lb;
			//[i,r] -> ?
			int x = ran[i];
			lb = -1,ub = x;
			while(ub-lb > 1){
				int mid = (lb+ub)/2;
				if(calc(mid,x) >= r-i+1) ub = mid;
				else lb = mid;
			}
			int ll = ub;
			lb = x, ub = n+1;
			while(ub-lb > 1){
				int mid = (lb+ub)/2;
				if(calc(x,mid) >= r-i+1) lb = mid;
				else ub = mid;
			}
			//[ll,rr]
			int rr = lb;
			int nxt = kaede.query(ll,rr+1);
			if(nxt >= n) break;
			else{
				pre = r;
				r = nxt+r-i;
			}
		}
		ret = max(ret,ans);
	}
	cout << ret << endl;
	return 0;
}