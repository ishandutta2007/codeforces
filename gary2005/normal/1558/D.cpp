/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
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
/*}
*/

const int MOD=998244353;
const int MAXN=4e5+1;
int quick(int A,int B){
    if(B==0) return 1;
    int tmp=quick(A,B>>1);
    tmp=1ll*tmp*tmp%MOD;
    if(B&1) tmp=1ll*tmp*A%MOD;
    return tmp;
}
int inv(int A){return quick(A,MOD-2);}
int fact[MAXN],ifact[MAXN];
int comb(int A,int B){
    return 1ll*fact[A]*ifact[B]%MOD*ifact[A-B]%MOD;
}
/*------------------templet---begin-----------------------*/
SRAND;
vector<mp> gt;
struct Treap{
	int root=0;
	struct node{
        mp val;
        int ran,l,r,siz;
	};
	vector<node> v;
	int new_node(mp val){
		if(v.empty()){
			v.PB(node{II(0,-1),(int)random(INF),0,0,0});
		}
		v.PB(node{val,(int)random(INF),0,0,val.SEC-val.FIR+1});
		return v.size()-1;
	}
	void update(int index){
		v[index].siz=v[index].val.SEC-v[index].val.FIR+1;
		if(v[index].l){
			v[index].siz+=v[v[index].l].siz;
		}
		if(v[index].r){
			v[index].siz+=v[v[index].r].siz;
		}
	}
    void split_by_size(int base,int & x,int & y,int boundary){
		if(!boundary){
			x=0;
			y=base;
			return;
		}
		if(!base){
			x=y=0;
			return;
		}
		if(v[v[base].l].siz+v[base].val.SEC-v[base].val.FIR+1<boundary){
			x=base;
			split_by_size(v[base].r,v[x].r,y,boundary-v[v[base].l].siz-(v[base].val.SEC-v[base].val.FIR+1));
			update(x);
		}
		else{
		    y=base;
			split_by_size(v[base].l,x,v[y].l,boundary);
			update(y);
		}
	}
    void getleft(int base,int & x,int & y){
		if(!base){
			x=y=0;
			return;
		}
		if(!v[base].l){
            x=base;
            y=v[base].r;
            v[base].r=0;
            update(x);
		}
		else{
		    y=base;
			getleft(v[base].l,x,v[y].l);
			update(y);
		}
	}
	int merge(int x,int y){
		if(x==0||y==0) return x+y;
		if(v[x].ran>v[y].ran){
			v[x].r=merge(v[x].r,y);
			update(x);
			return x;	
		}
		v[y].l=merge(x,v[y].l);
		update(y);
		return y;
	}
    void traval(int now){
        if(now==0) return ;
        traval(v[now].l);
        gt.PB(v[now].val);
        traval(v[now].r);
    }
}fhq;
/*------------------templet---end-----------------------*/
int x[MAXN],y[MAXN];
void solve(){
    fhq.v.clear();
    fhq.root=0;
    int n,m;
    scanf("%d%d",&n,&m);
    rb(i,1,m){
        scanf("%d%d",&x[i],&y[i]);
    }
    vector<pair<mp,int> > can;
    int pre=0;
    rb(i,1,m){
        if(pre+1<=x[i]-1){
            can.PB(II(II(pre+1,x[i]-1),n));
        }
        can.PB(II(II(x[i],x[i]),y[i]));
        pre=x[i];
    }
    for(auto it:can){
        // cout<<it.FIR.FIR<<"_"<<it.FIR.SEC<<endl;
        if(it.SEC==n){
            fhq.root=fhq.merge(fhq.root,fhq.new_node(it.first));
        }
        else{
            int x,y;
            fhq.split_by_size(fhq.root,x,y,it.SEC);
            int z;
            fhq.getleft(y,z,y);
            int nw=fhq.new_node(it.FIR);
            it.SEC-=fhq.v[x].siz;
            int _,__;
            _=__=0;
            it.SEC--;
            mp orz=fhq.v[z].val;
            if(it.SEC){
                _=fhq.new_node(II(orz.FIR,orz.FIR+it.SEC-1));
            }
            if(it.SEC!=fhq.v[z].siz){
                __=fhq.new_node(II(orz.FIR+it.SEC,orz.SEC));
            }
            // cout<<x<<" "<<_<<" "<<__<<" "<<z<<" "<<" "<<y<<endl;
            fhq.root=fhq.merge(x,fhq.merge(fhq.merge(fhq.merge(_,nw),__),y));
        }
    }
    gt.clear();
    fhq.traval(fhq.root);
    int cnt=0;
    rep(i,gt.size()){
        // rb(j,gt[i].FIR,gt[i].SEC) cout<<j<<",";
        if(i){
            if(gt[i-1].SEC>gt[i].FIR){
                cnt++;
            }
        }
    }
    // cout<<endl;
    int ans=comb(n-1+n-1-cnt+1,n);
    printf("%d\n",ans);
}
int main(){
    fact[0]=1;
    rb(i,1,400000) fact[i]=1ll*fact[i-1]*i%MOD;
    rb(i,0,400000) ifact[i]=inv(fact[i]);
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}