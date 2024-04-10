/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=3e3+20;
vector<LL> a[MAXN];
int t[MAXN];
LL sum[MAXN];
int n,k;
vector<LL> dfs(int l,int r){
	vector<LL> v(k+1,0);
	if(l>r) return v;
	if(l==r){
		return a[l];
	}
	vector<LL> L,R;
	int mid=(l+r)>>1;
	L=dfs(l,mid);
	rb(i,mid+1,r){
		rl(j,k,t[i])
			check_max(L[j],L[j-t[i]]+sum[i]);
	}	
	R=dfs(mid+1,r);
	rb(i,l,mid){
		rl(j,k,t[i])
			check_max(R[j],R[j-t[i]]+sum[i]);
	}
	rb(i,0,k)
		v[i]=max(L[i],R[i]);
	return v;
}
int main(){
	scanf("%d%d",&n,&k);
	rb(i,1,n) {
		int ti;
		scanf("%d",&ti);
		a[i].PB(0);
		rb(j,1,ti){
			int ai;
			scanf("%d",&ai);
			a[i].PB(ai);
			if(j<=k)
				sum[i]+=ai;
		}
		t[i]=min(k,ti);
		LL sum=0;
		for(auto& it : a[i]){
			sum+=it;
			it=sum;	
		}	
		a[i].resize(k+1);
		LL ma=0;
		for(auto& it : a[i]){
			check_max(ma,it);
			it=ma;
		}
	}
	vector<LL> rest=dfs(1,n);
	cout<<rest[k]<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/