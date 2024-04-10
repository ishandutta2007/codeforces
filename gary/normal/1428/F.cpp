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
int n;
string s;
int Id[500000+20],l[500000+20],r[500000+20];
int rt[500000+20],lt[500000+20];
const int N=1<<19; 
struct SGT{
	int tree[N+N];
	void clear(){
		memset(tree,63,sizeof(tree));
	}
	void Set(int index,int val){
		index+=N-1;
		check_min(tree[index],val);
		index>>=1;
		while(index){
			tree[index]=min(tree[index<<1],tree[index<<1|1]);
			index>>=1;
		} 
	}
	int query(int a,int b,int now=1,int l=1,int r=N+1){
		if(r<=a||l>=b){
			return INF;
		}
		if(r<=b&&l>=a){
			return tree[now];
		}
		int mid=(l+r)>>1;
		return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
}sgt;
LL Sum(LL X){
	return X*(X+1)/2;
}
int main(){
	cin>>n>>s;
	int id=0;
	rep(i,n){
		if((i==0||s[i-1]=='0')&&s[i]=='1'){
			id++;
		}
		if(s[i]=='1'){
			Id[i]=id;
		}
	}
	rb(i,1,id)
		l[i]=INF,r[i]=-INF;
	rep(i,n){
		if(Id[i]){
			check_min(l[Id[i]],i);
			check_max(r[Id[i]],i);
		}
	}
//	rb(i,1,id){
//		cout<<l[i]<<' '<<r[i]<<endl;
//	}
	sgt.clear();
	rl(i,n-1,0){
		if(i!=n-1&&(s[i+1]=='1')&&s[i]=='0'){
			sgt.Set(r[Id[i+1]]-l[Id[i+1]]+1,Id[i+1]);
		}
		if(s[i]=='1'){
			rt[i]=n-1;
			int id_=sgt.query(r[Id[i]]-i+2,N+1);
			if(id_==INF) continue;
			int L=l[id_];
			L+=(r[Id[i]]-i+1);
			L--;
			rt[i]=L;
		}
	}
	sgt.clear();
	rb(i,0,n-1){
		if(i!=0&&(s[i-1]=='1'&&s[i]=='0')){
//			cout<<r[Id[i-1]]-l[Id[i-1]]+1<<'!'<<endl;
			sgt.Set(r[Id[i-1]]-l[Id[i-1]]+1,-Id[i-1]);
		}
		if(s[i]=='1'){
			lt[i]=0;
			int id_=sgt.query(i-l[Id[i]]+1,N+1);
			if(id_==INF) continue;
			id_=-id_;
//			cout<<id_<<'*'<<i<<endl;
			int R=r[id_];
			R-=(i-l[Id[i]]);
			R++;
			lt[i]=R;
		}
	}
//	rb(i,0,n-1){
//		cout<<rt[i]<<' ';
//	}
//	cout<<endl;
//	rb(i,0,n-1) cout<<lt[i]<<' ';
//	cout<<endl;
	LL rest=0; 
	rb(i,1,id){
		rb(j,l[i],r[i]){
			rest+=Sum(r[i]-j+1);
		}
//		cout<<rest<<endl;
		rest-=(r[i]-l[i]+1);
		LL LLL,RRR;
		LLL=l[i]-lt[r[i]]+1;
		RRR=rt[l[i]]-r[i]+1;
//		cout<<LLL<<' '<<RRR<<' '<<rest<<endl;
		rest+=LLL*RRR*(r[i]-l[i]+1);
		rb(j,l[i]+1,r[i]){
			rest+=1ll*(r[i]-j+1)*(rt[j]-r[i]);
		}
		rl(j,r[i]-1,l[i]){
			rest+=1ll*(j-l[i]+1)*(l[i]-lt[j]);
		}
	}
	cout<<rest<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/