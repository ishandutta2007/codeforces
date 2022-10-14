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
map<int,int> mx,my;
const int MOD=1e9+7;
int n,N,M,k,l,realx[2055],realy[2055],x[2005],y[2005],c[2005];
LL quick(int A,int B){
	if(!B) return 1ll;
	LL tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1){
		tmp*=A;
		tmp%=MOD;
	}
	return tmp;
}
multiset<int> s[2005];
multiset<int> :: IT ite; 
vector<mp> have[2005];
LL pre1[2005],pre2[2005],cnt[2005]; // \sum diff , \sum diff*real
struct node{
	LL mi,se,sum,rest;/*  \sum diff[i]*/
};
const int MAXN=1<<11;
node tree[MAXN+MAXN];
int tag[MAXN+MAXN];
void build(int index){
	if(index>=MAXN){
		tree[index]=node{0,INF,realy[index-MAXN+1]-realy[index-MAXN],0};
	}
	else{
		build(index<<1);
		build(index<<1|1);
		tree[index].mi=0;
		tree[index].se=INF;
		tree[index].sum=tree[index<<1].sum+tree[index<<1|1].sum;
		tree[index].sum%=MOD;
		tree[index].rest=0;
	} 
}
void push_up(int index){
	tree[index].mi=min(tree[index<<1].mi,tree[index<<1|1].mi);
	tree[index].se=INF;
	if(tree[index<<1].mi!=tree[index].mi){
		check_min(tree[index].se,tree[index<<1].mi);
	}
	else{
		check_min(tree[index].se,tree[index<<1].se);
	}
	if(tree[index<<1|1].mi!=tree[index].mi){
		check_min(tree[index].se,tree[index<<1|1].mi);
	}
	else{
		check_min(tree[index].se,tree[index<<1|1].se);
	}
	tree[index].sum=0;
	if(tree[index<<1].mi==tree[index].mi){
		tree[index].sum+=tree[index<<1].sum;
		tree[index].sum%=MOD;
	}
	if(tree[index<<1|1].mi==tree[index].mi){
		tree[index].sum+=tree[index<<1|1].sum;
		tree[index].sum%=MOD;
	}
	tree[index].rest=tree[index<<1].rest+tree[index<<1|1].rest;
	tree[index].rest%=MOD;
} 
void add_tag(int index,int x){
	if(x<=tree[index].mi) return;
	if(x<tree[index].se){
		tag[index]=max(tag[index],x);
		tree[index].rest+=1ll*(x-tree[index].mi)*tree[index].sum;
		tree[index].rest%=MOD;
		tree[index].mi=x;
		return;
	}
	add_tag(index<<1,x);
	add_tag(index<<1|1,x);
	push_up(index);
}
void push_down(int index){
	add_tag(index<<1,tag[index]);
	add_tag(index<<1|1,tag[index]);
	tag[index]=0;
}

void Check_Max(int a,int b,int val,int now=1,int l=1,int r=MAXN+1){
	if(r<=a||l>=b){
		return;
	}	
	if(r<=b&&l>=a){
		add_tag(now,val);
		return;
	}
	push_down(now);
	int mid=(l+r)>>1;
	Check_Max(a,b,val,now<<1,l,mid);
	Check_Max(a,b,val,now<<1|1,mid,r);
	push_up(now);
}
signed main(){
	R2(n,k);
	R(l);
	int cnt_=0;
	mx[0]=my[0]=1;
	mx[l+1]=my[l+1]=1;
	rb(i,1,n){
		cin>>x[i]>>y[i]>>c[i];
		x[i]++;
		y[i]++;
		mx[x[i]]=1;
		my[y[i]]=1;
	}
	cnt_=0;
	for(map<int,int> :: IT ite=mx.begin();ite!=mx.end();ite++){realx[cnt_]=ite->FIR;ite->SEC=cnt_++;}
	N=cnt_-2;
	cnt_=0;
	for(map<int,int> :: IT ite=my.begin();ite!=my.end();ite++){realy[cnt_]=ite->FIR;ite->SEC=cnt_++;}
	M=cnt_-2;
	rb(i,1,n)
		x[i]=mx[x[i]],y[i]=my[y[i]];
	LL rest=0;
	rb(i,1,M){
		pre1[i]=pre1[i-1];
		pre2[i]=pre2[i-1];
		pre1[i]+=realy[i]-realy[i-1];
		pre1[i]%=MOD;
		pre2[i]+=1ll*(realy[i]-realy[i-1])*realy[i]%MOD;
		pre2[i]%=MOD;
	}	
	LL hooo=pre1[M];
	hooo*=(l+1);
	hooo%=MOD;
	rb(bot,1,N){
		memset(tag,0,sizeof(tag));
		build(1);
		int pi=1,have_=0;
		rb(i,1,k)
			cnt[i]=0;
		vector<mp> v;
		rb(i,1,N)
			have[i].clear();
		rb(i,1,k)
			s[i].clear();
		rb(i,1,n)
		{
			if(x[i]<=bot){
				v.PB(II(y[i],c[i]));
				s[c[i]].insert(y[i]);
				have[x[i]].PB(II(y[i],c[i]));
			}
		}
		rb(i,1,k)
			s[i].insert(M+1);
		sort(ALL(v));
		int is=0;		
		rb(i,1,M){
			while(is<v.size()&&v[is].FIR<=i){
				if(!cnt[v[is].SEC]){
					have_++;
				}
				cnt[v[is].SEC]++;
				is++;
			}
			if(have_==k)  break;
			pi=i+1;
		}
		int iss=0;
		rb(i,1,M){
			while(have_!=k&&is<v.size()){
				pi=v[is].FIR;
				if(!cnt[v[is].SEC]){
					have_++;
				}
				cnt[v[is].SEC]++;
				is++;
			}
			while(is<v.size()&&v[is].FIR<=pi){
				cnt[v[is].SEC]++;
				is++;
			}
			if(have_!=k){
				pi=M+1;
			}
			Check_Max(i,i+1,realy[pi]);	
			while(iss<v.size()&&v[iss].FIR<=i){
				cnt[v[iss].SEC]--;
				if(!cnt[v[iss].SEC]){
					have_--;
				}
				iss++;
			}
		}
		rb(top,1,bot){
			for(auto it:have[top-1]){
				s[it.SEC].erase(s[it.SEC].find(it.FIR));
					int l,r;
					ite=s[it.SEC].lower_bound(it.FIR);
					r=realy[*ite];
					ite=s[it.SEC].upper_bound(it.FIR);
					if(ite!=s[it.SEC].begin()){
						ite--;
						l=*ite;
					}
					else{
						l=0;
					}
					l++;
					if(l<=it.FIR)
					Check_Max(l,it.FIR+1,r);
			} 
			rest+=((hooo-tree[1].rest)+MOD)%MOD*(realx[top]-realx[top-1])%MOD*(realx[bot+1]-realx[bot])%MOD;//p[i]*diff[i]
			rest%=MOD;
		}
	}
	cout<<rest<<endl;
	return 0;
}
/*
20 7 100
37 42 3
39 80 3
37 53 2
39 73 6
35 10 1
88 10 5
9 20 4
0 42 2
0 97 4
47 97 7
68 38 5
89 80 3
82 10 6
37 28 5
35 3 6
37 80 4
35 53 5
9 42 3
88 42 7
39 10 2
*/