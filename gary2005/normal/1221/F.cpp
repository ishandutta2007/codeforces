/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int N=1<<19;
struct SEGMENTTREE{
	pair<LL,int> tree[N+N];
	LL tag[N+N];
	SEGMENTTREE (){
	rb(i,1,N)
		tree[i+N-1]=II(0,i);
	rl(i,N-1,1)
		tree[i]=max(tree[i<<1],tree[i<<1|1]);
	memset(tag,0,sizeof(tag));}
	void pd(int now){
		tree[now].FIR+=tag[now];
		if(now<N) tag[now<<1]+=tag[now],tag[now<<1|1]+=tag[now];
		tag[now]=0;
	}
	void pu(int now){
		tree[now]=max(tree[now<<1],tree[now<<1|1]);
	}
	void add(int a,int b,int val,int now=1,int l=1,int r=N+1){
		pd(now);
		if(r<=b&&l>=a){
			tag[now]+=val;
			pd(now);
			return ;
		}
		if(r<=a||l>=b){
			return;
		}
		int mid=(l+r)>>1;
		add(a,b,val,now<<1,l,mid);
		add(a,b,val,now<<1|1,mid,r);
		pu(now);
	}
	pair<LL,int> query(int a,int b,int now=1,int l=1,int r=N+1){
		pd(now);
		if(a==b) return II(-1e18,-1e18);
		if(r<=b&&l>=a) return tree[now];
		if(r<=a||l>=b) return II(-1e18,-1e18);
		int mid=(l+r)>>1;
		return max(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
	}
};
/*}
*/
int getr(int x,int y){
	return max(x,y);	
}
int getl(int x,int y){
	return min(x,y);
}
vector<int> l,r;
vector<vector<mp> > vl;
int findl(int x){
	return lower_bound(ALL(l),x)-l.begin();
}
int findr(int x){
	return lower_bound(ALL(r),x)-r.begin()+1;
}
const int MAXN=5e5+20;
int n,x[MAXN],y[MAXN],c[MAXN];
SEGMENTTREE sgt;
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d%d%d",&x[i],&y[i],&c[i]),l.PB(getl(x[i],y[i])),r.PB(getr(x[i],y[i]));
	sort(ALL(l));
	l.erase(unique(ALL(l)),l.end());
	sort(ALL(r));
	r.erase(unique(ALL(r)),r.end());
//	for(auto it:l){
//		cout<<it<<' ';
//	}
//	cout<<endl;
//	for(auto it:r){
//		cout<<it<<' ';
//	}
//	cout<<endl;
	vl.resize(l.size());
	rb(i,1,r.size()){
		sgt.add(i,i+1,-r[i-1]);
	}
	rb(i,1,n){
		sgt.add(findr(getr(x[i],y[i])),r.size()+1,c[i]);
	}
	rb(i,1,n){
		vl[findl(getl(x[i],y[i]))].PB(II(findr(getr(x[i],y[i])),c[i]));
	}
	pair<LL,mp> rest;
	rest=II(0,II(2e9,2e9));
	rep(i,vl.size()){
		auto Era=vl[i];
		int z=findr(l[i]);
		pair<LL,mp> tmp;
		pair<LL,int> ttmp=sgt.query(z,r.size()+1);
//		if(l[i]==3){
//			cout<<ttmp.FIR<<' '<<ttmp.SEC<<endl;
//		}
		ttmp.FIR+=l[i];
		tmp.FIR=ttmp.FIR;
		tmp.SEC.FIR=l[i];
		tmp.SEC.SEC=r[ttmp.SEC-1];
		check_max(rest,tmp);
		for(auto Eve:Era){
//			cout<<"-------------"<<Eve.FIR<<' '<<Eve.SEC<<endl;
			sgt.add(Eve.FIR,r.size()+1,-Eve.SEC);
		}
	}
	cout<<rest.FIR<<endl<<rest.SEC.FIR<<' '<<rest.SEC.FIR<<' '<<rest.SEC.SEC<<' '<<rest.SEC.SEC<<endl; 
	return 0;
}
/*
10
10 0 -1
1 10 -4
3 6 3
4 2 -5
10 7 -1
3 7 3
3 7 -2
8 10 4
5 0 -1
2 3 3



*/