/*
AuThOr Gwj
*/
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n;
const int MAXN=2e5;
int delta[MAXN*8][2],tree[MAXN*8][2];
vector<pair<int,bool > > rsave[MAXN*2];
const int N=1<<19;
int add(int a,int b,bool flag,int now=1,int l=1,int r=N+1){
	if(r<=a||l>=b){
		return tree[now][flag]+delta[now][flag];
	}
	if(r<=b&&l>=a){
		delta[now][flag]++;
//		cout<<l<<" "<<b<<endl;
		return tree[now][flag]+delta[now][flag];
	}
	int mid=(l+r)>>1;
	return (tree[now][flag]=max(add(a,b,flag,now<<1,l,mid),add(a,b,flag,now<<1|1,mid,r)))+delta[now][flag];
}
int query(int a,int b,bool flag,int now=1,int l=1,int r=N+1){
//		cout<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
	if(r<=a||l>=b) return 0;
	if(r<=b&&l>=a){
		return tree[now][flag]+delta[now][flag];
	}
	int mid=(l+r)>>1;
//	cout<<l<" "
	return max(query(a,b,flag,now<<1,l,mid),query(a,b,flag,now<<1|1,mid,r))+delta[now][flag];
}
void push_down(int index,bool flag){
	delta[index<<1][flag]+=delta[index][flag];
	delta[index<<1|1][flag]+=delta[index][flag];
	tree[index][flag]+=delta[index][flag];
	delta[index][flag]=0;
}
void go(int a,bool flag,int now=1,int l=1,int r=N+1){
	if(r<=a||l>a){
		return;
	}
	if(l==r-1){
		tree[now][flag]+=delta[now][flag];
		delta[now][flag]=0;
		return;	
	} 
	push_down(now,flag);
	int mid=(l+r)>>1;
	go(a,flag,now<<1,l,mid);
	go(a,flag,now<<1|1,mid,r);
}
void change(int index,bool flag,int val){
	index+=N-1;
	tree[index][flag]=val;
	index>>=1;
	while(index){
		tree[index][flag]=max(
		tree[index<<1][flag]+delta[index<<1][flag],
		tree[index<<1|1][flag]+delta[index<<1|1][flag]
		);
		index>>=1;
	}
}
vector<mp> seg[2];
map<int,int> m;
int main(){
	fastio;
	R(n);
	rb(i,1,n){
		int l,R;
		R2(l,R);
		int co;
		R(co);
		co--;
		seg[co].PB(II(l,R)); 
		m[l]=m[R]=1;
	}
	int cnt=0;
	for(map<int,int> :: IT ite=m.begin();ite!=m.end();ite++){
		ite->SEC=++cnt; 
	}
	for(auto it:seg[0]){
		it.FIR=m[it.FIR];
		it.SEC=m[it.SEC];
//		cout<<it.FIR<<" "<<it.SEC<<" "<<0<<endl;
		rsave[it.FIR].PB(II(it.SEC,0));
	}
	for(auto it:seg[1]){
		it.FIR=m[it.FIR];
		it.SEC=m[it.SEC];
//		cout<<it.FIR<<" "<<it.SEC<<" "<<1<<endl;
		rsave[it.FIR].PB(II(it.SEC,1));
	}
	rl(i,cnt,1){
		for(auto it:rsave[i]){
			if(it.SEC==1){
				add(it.FIR+1,N+1,0);
			}
			else{
				add(it.FIR+1,N+1,1);
			}
		}
		go(i,0);
		go(i,1); 
		change(i,0,query(i+1,N+1,1));
		change(i,1,query(i+1,N+1,0));
	}
	cout<<max(query(1,cnt+1,0),query(1,cnt+1,1))<<endl;
	return 0;
}