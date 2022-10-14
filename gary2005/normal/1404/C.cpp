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
const int N=1<<19;
int tag[N+N],tree[N+N];
void push_down(int index){
	tree[index]+=tag[index];
	if(index<N){
		tag[index<<1]+=tag[index];
		tag[index<<1|1]+=tag[index];
	}
	tag[index]=0;
}
void push_up(int index){
	tree[index]=tree[index<<1];
}
void modify(int a,int b,int now=1,int l=1,int r=N+1){
	push_down(now);
	if(r<=a||l>=b){
		return;
	}
	if(r<=b&&l>=a){
		tag[now]++;
		push_down(now);
		return;
	}
	int mid=(l+r)>>1;
	modify(a,b,now<<1,l,mid);
	modify(a,b,now<<1|1,mid,r);
	push_up(now);
}
int low_bound(int val,int now=1){
	push_down(now);
	if(tree[now]<val){
		return 0;
	}
	if(now>=N){
		return now-N+1;
	}
	push_down(now<<1);
	push_down(now<<1|1);
	if(tree[now<<1|1]>=val){
		return low_bound(val,now<<1|1);
	} 
	return low_bound(val,now<<1);
}
int n,q,a[N],reach[N];
int bit[N+10]={0};
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&(-i);
	}
	return s;
}
void add(int i,int x=1){
	while(i<=N){
		bit[i]+=x;
		i+=i&(-i);	
	}
}
int rest[300000+10];
int main(){
	R2(n,q);
	rb(i,1,n){
		R(a[i]);
	}
	vector<mp> tmpp;
	rb(i,1,n){
		int iis=low_bound(i-a[i]);
		iis=min(iis,i);
		if(a[i]>i){
//			cout<<"!"<<endl;
			iis=0;
		}
		reach[i]=iis;
//		cout<<"$"<<iis<<endl;
		tmpp.PB(II(iis,i));
		if(iis) modify(1,iis+1);
	}
	sort(ALL(tmpp));
	vector<pair<mp,int>  > qq;
	rb(i,1,q){
		int x,y;
		cin>>x>>y;
		qq.PB(II(II(x+1,n-y),i));
	}
	sort(ALL(qq));
	reverse(ALL(qq));
	for(auto it:qq){
		while(tmpp.size()&&tmpp.back().FIR>=it.FIR.FIR){
			add(tmpp.back().SEC);
			tmpp.POB();
		}
		rest[it.SEC]=sum(it.FIR.SEC)-sum(it.FIR.FIR-1);
	}
	rb(i,1,q){
		cout<<rest[i]<<endl;
	}
	return 0;
}