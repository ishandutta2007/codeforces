/*
{By GWj
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=500000+20; 
int n;
vector<int> c[MAXN];
const int N=1<<19;
struct segtree{
	mp tree[N+N];
	int lazy_tag[N+N];
	mp merge(mp A,mp B){
		mp rest=II(0,0);
		rest.FIR=max(A.FIR,B.FIR);
		if(A.FIR==rest.FIR){
			rest.SEC+=A.SEC;
		}
		if(B.FIR==rest.FIR){
			rest.SEC+=B.SEC;
		}
		return rest;
	}
	void mian(){
		rb(i,N,N+N-1) tree[i]=II(0,1);
		rb(i,1,N-1) tree[i]=merge(tree[i<<1],tree[i<<1|1]);
	}
	void push_down(int index){
		tree[index].FIR+=lazy_tag[index];
		if(index<N){
			lazy_tag[index<<1]+=lazy_tag[index];
			lazy_tag[index<<1|1]+=lazy_tag[index];
		}
		lazy_tag[index]=0;
	}
	void modify(int a,int b,int val,int now=1,int l=1,int r=N+1){
		push_down(now);
		if(r<=a||l>=b){
			return;
		}
		if(r<=b&&l>=a){
			lazy_tag[now]+=val;
			push_down(now);
			return;
		}
		int mid=(l+r)>>1;
		modify(a,b,val,now<<1,l,mid);
		modify(a,b,val,now<<1|1,mid,r);
		tree[now]=merge(tree[now<<1],tree[now<<1|1]);
	}
	mp query(int a,int b,int now=1,int l=1,int r=N+1){
		push_down(now);
		if(r<=a||l>=b){
			return II(0,0);
		}
		if(r<=b&&l>=a){
			return tree[now];
		}
		int mid=(l+r)>>1;
		return merge(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
}t;
int a[MAXN];
void paint(int l,int r,int ll,int cal){
	if(l){
		ll++;
		if(l>=ll)
		t.modify(ll,l+1,cal);
	}	
	if(r!=n){
		t.modify(r+1,n+1,cal);
	}
}
int main(){
	fastio;
	R(n);
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	t.mian();
	rb(i,1,n)
		R(a[i]);
	rb(i,1,n) rep(j,5) c[i].PB(0);
	rb(i,1,n){
		c[a[i]].PB(i);
	}
	/*
		for each color i l-bonud must lie in the range (las_app,r] or (fourth_app,third_app]
	*/
	rb(i,1,n){
		int l,r;
		r=c[i].back();
		l=c[i][c[i].size()-3];
		int ll=c[i][c[i].size()-4];
		paint(l,r,ll,1);
	} 
	LL rest=0;
	rl(i,n,1){
		if(i!=n){
			int col=a[i+1];
			int l,r,ll;
			r=c[col].back();
			l=c[col][c[col].size()-3];
			ll=c[col][c[col].size()-4];
			paint(l,r,ll,-1);
			c[col].POB();
			r=c[col].back();
			l=c[col][c[col].size()-3];
			ll=c[col][c[col].size()-4];
			paint(l,r,ll,1);
		}
		mp q=t.query(1,i);
		if(q.FIR==n) rest+=q.SEC;
//		cout<<"# "<<q.FIR<<" "<<q.SEC<<endl.;
	}
	cout<<rest<<endl;
	return 0;
}