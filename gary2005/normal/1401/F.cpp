/*
{

AuThOr Gwj
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
struct node{
	int cnt_rev;LL sum;int cnt_swp;
	int l,r;
};
int N; 
node tree[(1<<18)*2];
int rev[19],swp[19];
int n;
void push_down(int index,int cen){
	int need=rev[cen]-tree[index].cnt_rev;
	int l,r;
	l=tree[index].l;
	r=tree[index].r;
	if(need&1){
		tree[l].cnt_rev--;
		tree[r].cnt_rev--;
		swap(tree[index].l,tree[index].r);
	}
	tree[index].cnt_rev=rev[cen];
	need=swp[cen]-tree[index].cnt_swp;
	if(need&1){
//		cout<<index<<" "<<tree[index].l<<" "<<tree[index].r<<" "<<tree[tree[index].l].sum<<" "<<tree[tree[index].r].sum<<endl;
		swap(tree[index].l,tree[index].r);
	}
	tree[index].cnt_swp=swp[cen];
}
void modify(int index,int val,int now=1,int l=1,int r=N+1,int cen=1){
	if(cen!=n+1) push_down(now,cen);
	if(r<=index||l>index){
		return ;
	}
	if(r==l+1){
		tree[now].sum=val;
		return;
	} 
	int mid=(l+r)>>1;
	modify(index,val,tree[now].l,l,mid,cen+1);
	modify(index,val,tree[now].r,mid,r,cen+1);
	tree[now].sum=tree[tree[now].l].sum+tree[tree[now].r].sum;
}
LL query(int a,int b,int now=1,int l=1,int r=N+1,int cen=1){
	if(cen!=n+1) push_down(now,cen);
	if(r<=a||l>=b){
		return 0ll;
	}
	if(r<=b&&l>=a){
//		cout<<now<<endl; 
		return tree[now].sum;
	}
	int mid=(l+r)>>1;
	return query(a,b,tree[now].l,l,mid,cen+1)+query(a,b,tree[now].r,mid,r,cen+1);
}
int main(){
	fastio;
	cin>>n;
	N=1<<n;
	int q;
	R(q);
	rep(i,2*N){
		tree[i].cnt_rev=tree[i].cnt_swp=tree[i].sum=0;
		if(i>=N) continue;
		tree[i].l=i<<1;
		tree[i].r=i<<1|1;
	}
	rb(i,1,1<<n){
		int ai;
		R(ai);
		modify(i,ai);
	}
//	cout<<tree[5].sum<<endl;
	while(q--){
		int ty;
		R(ty);
		if(ty==1){
			int x,k;
			R2(x,k); 
			modify(x,k);
		}
		if(ty==2){
			int k;
			R(k);
			if(k==0) continue; 
			rev[n-k+1]++;
		}
		if(ty==3){
			int k;
			R(k);
			swp[n-k]++;
		}
		if(ty==4){
			int l,r;
			R2(l,r);
			cout<<query(l,r+1)<<endl;
		}
	}
	return 0;
}