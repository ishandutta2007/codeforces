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
int NN,k;
int ran[500005];
int tmp[500005];
int sa[500005];
 
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
int lcp[500005];
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
 
 
int n;
string s;
int pos[500005];
int mn[500005][20];
 
struct per_seg{
	const static int sz = (1<<19);
	vector<int>root;
	int L[20000005],R[20000005],id;
	int seg[20000005];
	void make(){
		for(int i=0;i<sz-1;i++) L[i] = i*2+1,R[i] = i*2+2;
		root.push_back(0); id = 2*sz;
	}
	int update(int a,int k,int l,int r,int st){
		if(l==r){
			seg[id] = st;
			return id++;
		}
		if(l<=a && a<=(l+r)/2){
			int x = update(a,L[k],l,(l+r)/2,st);
			seg[id] = max(seg[x],seg[R[k]]);
			L[id] = x; R[id] = R[k];
			return id++;
		}
		else{
			int x = update(a,R[k],(l+r)/2+1,r,st);
			seg[id] = max(seg[L[k]],seg[x]);
			L[id] = L[k]; R[id] = x;
			return id++;
		}
	}
	//call update -> new root will be made
	void update(int pos,int st){
		int R = root.back();
		int nw = update(pos,R,0,sz-1,st);
		root.push_back(nw);
	}
	int query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return 0;
		if(a<=l && r<=b) return seg[k];
		return max(query(a,b,L[k],l,(l+r)/2),query(a,b,R[k],(l+r)/2+1,r));
	}
	int query(int ver,int l,int r){
		return query(l,r,root[ver],0,sz-1);
	}
}kaede;

int len[500005];
int rng_min(int x,int y){
    if(x > y) return INF;
    int a = len[y-x+1];
    return min(mn[x][a],mn[y-(1<<a)+1][a]);
}
int main(){
	cin >> n >> s;
	construct_sa(s);
	construct_lcp(s);
	rep(i,500005) rep(j,20) mn[i][j] = INF;
	for(int i=0;i<s.size();i++){
		mn[i][0] = lcp[i];
	}
	for(int i=1;i<=500005;i++){
	    for(int j=0;;j++){
	        if((2<<j) >= i) {len[i]=j;break;}
	    }
	}
	for(int j=0;j<19;j++){
		for(int i=0;i<s.size();i++){
			if(i+(1<<j) >= s.size()) mn[i][j+1] = mn[i][j];
			else mn[i][j+1] = min(mn[i][j],mn[i+(1<<j)][j]);
		}
	}
	kaede.make();
	for(int i=n-1;i>=0;i--){
		int lb = 1, ub = 1001;
		while(ub-lb > 1){
			int mid = (lb+ub)/2;
			if(i+mid-1 > n-1){
				ub = mid; continue;
			}
			bool ok = 0;
			for(int j=i;j<=i+1;j++){
				int x = ran[j];
				int lbb = x, ubb = n;
				while(ubb-lbb > 1){
					int midd = (lbb+ubb)/2;
					if(rng_min(x,midd-1) >= mid-1) lbb = midd;
					else ubb = midd;
				}
				int R = lbb;
				lbb = -1, ubb = x;
				while(ubb-lbb > 1){
					int midd = (lbb+ubb)/2;
					if(rng_min(midd,x-1) >= mid-1) ubb = midd;
					else lbb = midd;
				}
				int L = ubb;
				if(kaede.query(n-i-mid,L,R) >= mid-1){
					ok = 1; break;
				}
			}
			if(ok) lb = mid;
			else ub = mid;
		}
		kaede.update(ran[i],lb);
		//cout << kaede.query(n-i,ran[i],ran[i]) << " " << lb << endl;
		//cout << ran[i] << " " << lb << endl;
	}
	cout << kaede.query(n,0,kaede.sz-1) << endl;
}