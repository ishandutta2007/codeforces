#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
struct dat{
	int pre_ones,pre_zeros;
	int suf_ones,suf_zeros;
	int pre_zero_ones,pre_one_zeros;
	int suf_zero_ones,suf_one_zeros;
	int zero_ones,one_zeros;
	int l;
};
void fff(dat &node){
	swap(node.pre_zeros,node.pre_ones);
	swap(node.suf_zeros,node.suf_ones);
	swap(node.zero_ones,node.one_zeros);
	swap(node.pre_zero_ones,node.pre_one_zeros);
	swap(node.suf_zero_ones,node.suf_one_zeros);
}
dat merge(dat &x,dat &y){
	dat res;
	res.pre_ones=x.pre_ones;
	if(x.pre_ones==x.l) res.pre_ones+=y.pre_ones;
	res.pre_zeros=x.pre_zeros;
	if(x.pre_zeros==x.l) res.pre_zeros+=y.pre_zeros;
	res.suf_ones=y.suf_ones;
	if(y.suf_ones==y.l) res.suf_ones+=x.suf_ones;
	res.suf_zeros=y.suf_zeros;
	if(y.suf_zeros==y.l) res.suf_zeros+=x.suf_zeros;
	res.pre_zero_ones=x.pre_zero_ones;
	if(x.pre_zeros==x.l) res.pre_zero_ones+=y.pre_zero_ones;
	else if(x.pre_zero_ones==x.l) res.pre_zero_ones+=y.pre_ones;
	res.pre_one_zeros=x.pre_one_zeros;
	if(x.pre_ones==x.l) res.pre_one_zeros+=y.pre_one_zeros;
	else if(x.pre_one_zeros==x.l) res.pre_one_zeros+=y.pre_zeros;
	res.suf_zero_ones=y.suf_zero_ones;
	if(y.suf_ones==y.l) res.suf_zero_ones+=x.suf_zero_ones;
	else if(y.suf_zero_ones==y.l) res.suf_zero_ones+=x.suf_zeros;
	res.suf_one_zeros=y.suf_one_zeros;
	if(y.suf_zeros==y.l) res.suf_one_zeros+=x.suf_one_zeros;
	else if(y.suf_one_zeros==y.l) res.suf_one_zeros+=x.suf_ones;	
	res.zero_ones=max({x.zero_ones,y.zero_ones,x.suf_zeros+y.pre_zero_ones,x.suf_zero_ones+y.pre_ones});
	res.one_zeros=max({x.one_zeros,y.one_zeros,x.suf_ones+y.pre_one_zeros,x.suf_one_zeros+y.pre_zeros});
	res.l=x.l+y.l;
	return res;
}
int n,q,a[500005];
string s;
dat seg[4*500005];
bool lazy[4*500005];
void build(int node,int start,int end){
	if(start==end){
		if(a[start]==0){
			seg[node].pre_zeros=1;
			seg[node].pre_one_zeros=1;
			seg[node].pre_zero_ones=1;
			seg[node].suf_zeros=1;
			seg[node].suf_one_zeros=1;
			seg[node].suf_zero_ones=1;
			seg[node].zero_ones=1;
			seg[node].one_zeros=1;
			seg[node].l=1;
		}
		else{
			seg[node].pre_ones=1;
			seg[node].pre_one_zeros=1;
			seg[node].pre_zero_ones=1;
			seg[node].suf_ones=1;
			seg[node].suf_one_zeros=1;
			seg[node].suf_zero_ones=1;
			seg[node].zero_ones=1;
			seg[node].one_zeros=1;
			seg[node].l=1;
		}
		return;
	}
	int mid=(start+end)>>1;
	build(node<<1,start,mid);
	build(node<<1|1,mid+1,end);
	seg[node]=merge(seg[node<<1],seg[node<<1|1]);
}
void update(int node,int start,int end,int l,int r,int val){
	if(lazy[node]!=0){
		fff(seg[node]);
		if(start!=end){
			lazy[node<<1]^=lazy[node];
			lazy[node<<1|1]^=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end || start>r || end<l) return;
	if(l<=start && end<=r){
		fff(seg[node]);
		if(start!=end){
			lazy[node<<1]^=val;
			lazy[node<<1|1]^=val;
		}
		return;
	}
	int mid=(start+end)>>1;
	update(node<<1,start,mid,l,r,val);
	update(node<<1|1,mid+1,end,l,r,val);
	seg[node]=merge(seg[node<<1],seg[node<<1|1]);
}
dat query(int node,int start,int end,int l,int r){
	if(start>end || start>r || end<l) return dat();
	if(lazy[node]!=0){
		fff(seg[node]);
		if(start!=end){
			lazy[node<<1]^=lazy[node];
			lazy[node<<1|1]^=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=l && end<=r) return seg[node];
	int mid=(start+end)>>1;
	dat q1=query(node<<1,start,mid,l,r);
	dat q2=query(node<<1|1,mid+1,end,l,r);
	return merge(q1,q2);
}
void solve(){
	cin>>n>>q;
	cin>>s;
	rep(i,1,n+1) a[i]=s[i-1]=='<';
	build(1,1,n);
	rep(i,0,q){
		int l,r;
		cin>>l>>r;
		update(1,1,n,l,r,1);
		dat res=query(1,1,n,l,r);
		cout<<max({res.pre_ones,res.suf_zeros,res.zero_ones})<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
    // cin>>t;
	while(t--){
		solve();
	}
	return 0;
}