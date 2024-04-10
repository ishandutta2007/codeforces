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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<pair<int,pair<mp,int> > >  q;
const int MAXN=1<<18;
int n,a[200000+1],tree[(200000)*8];
void add(int index){
	index+=MAXN-1;
	tree[index]++;
	index>>=1;
	while(index){
		tree[index]=tree[index<<1]+tree[(index<<1)+1];
		index>>=1;
	}
}
int query(int A,int B,int now,int l,int r){
	if(r<=A||l>=B){
		return 0;
	}
	if(r<=B&&l>=A){
		return tree[now];
	}
	int mid=(l+r)>>1;
	return query(A,B,now<<1,l,mid)+query(A,B,(now<<1)+1,mid,r);
}
int res[200000+20];
int main(){
	fastio;
	cin>>n;
	rb(i,1,n)
		cin>>a[i];
	vector<pair<int,int> >v;
	rb(i,1,n)
		v.PB(II(a[i],i));
	sort(ALL(v));
	rb(i,1,n-1)
	{
		int l,r;
		l=2,r=i+1;
		r=min(r,n);
		for(int j=1;j<=n;j++){
			if(l>r) break;
//			cout<<j<<" "<<l<<" "<<r<<" "<<i<<endl;
			q.PB(II(a[j]-1,II(II(l,r),i)));
			r+=i;
			l+=i;
			r=min(r,n);
		}
	}
	sort(ALL(q));
	int id=0;
	for(auto it:q){
		int val=it.FIR;
		while(id<n&&v[id].FIR<=val){
			add(v[id].SEC);
			id++;
		}
//		cout<<it.SEC.FIR.FIR<<" " 
		res[it.SEC.SEC]+=query(it.SEC.FIR.FIR,it.SEC.FIR.SEC+1,1,1,MAXN+1);
	}
	rb(i,1,n-1) cout<<res[i]<<" ";
	return 0;
}