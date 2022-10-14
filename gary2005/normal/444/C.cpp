/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=1e5;
int N;
LL addtree[200000*8],seg[200000*8]; 
LL ADD(int a,int b,int val,int l=1,int r=N+1,int now=1){
	if(r<=a||l>=b){
		return (LL)(r-l)*addtree[now]+seg[now];
	}
	if(r<=b&&l>=a){
		addtree[now]+=val;
		return (LL)(r-l)*addtree[now]+seg[now];
	}
	int mid=(l+r)>>1;
	return (seg[now]=ADD(a,b,val,l,mid,now<<1)+ADD(a,b,val,mid,r,(now<<1)+1))+(LL)(r-l)*addtree[now];
}
LL query(int a,int b,int l=1,int r=N+1,int now=1){
	if(r<=a||l>=b){
		return (LL)(0);
	}
	if(r<=b&&l>=a){
		return (LL)(r-l)*addtree[now]+seg[now];
	}
	int mid=(l+r)>>1;
	return query(a,b,l,mid,now<<1)+query(a,b,mid,r,(now<<1)+1)+(LL)(min(r,b)-max(a,l))*addtree[now];
}
int n,m;
set<mp/**/ >  s;
mp add[10];
int SZ=0;
void change(int l,int r,int v){
	mp new_seg;
	new_seg=II(l,v);
	set<mp> :: IT ite;
	SZ=0;
	add[++SZ]=new_seg;
	ite=s.upper_bound(II(l,-INF));
	if(ite==s.end()||(*ite).FIR!=l){
		ite--;
	}
	
	set<mp> :: IT nex;
	for(;ite!=s.end()&&(*ite).FIR<=r;ite=nex){
		ite++;
		nex=ite;
		ite--;
		int l_,r_;
		l_=(*ite).FIR;
		if(nex==s.end()){
			r_=n;
		} 
		else{
			r_=(*nex).FIR-1;
		}
		if(l_<l){
			
	add[++SZ]=II(l_,(*ite).SEC) ;
//			add.PB();
			l_=l;
		}
		if(r_>r){
			
	add[++SZ]= II(r+1,(*ite).SEC);
			r_=r;
		}
		ADD(l_,r_+1,abs(v-(*ite).SEC));
		s.erase(ite);
	} 
	if(SZ>3){
		cout<<"!!!erro"<<endl;
		exit(0);
	}
	for(int i=1;i<=SZ;i++){
		mp it=add[i];
		s.insert(it);
	}
}
int main(){
	fastio;
	cin>>n;
	N=1<<int(ceil(log2(double(n))));
	rb(i,1,n)
		s.insert(II(i,i));
	cin>>m;
	rb(i,1,m){
		int __;
		cin>>__;
		if(__==1){
			int l,r,v;
			cin>>l>>r>>v;
			change(l,r,v);
		}
		else{
			int l,r;
			cin>>l>>r;
			cout<<query(l,r+1)<<endl;
		}
	}
	return 0;
}