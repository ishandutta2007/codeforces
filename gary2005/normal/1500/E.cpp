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
static char buf[1000000],*p1=buf,*p2=buf,obuf[1000000],*p3=obuf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (p3-obuf<1000000)?(*p3++=x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x)
template<typename item>
inline void read(register item &x){
    x=0;register int f=1;register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=f;
}
template<typename item>
inline void uread(register item &x){
    x=0;register char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}//
static char cc[20];
template<typename item>
inline void print(register item x){ 
	if(x==0) {
		putchar('0');
		return ;	
	}
	register int len=0;
	if(x<0)x=-x,putchar('-');
	while(x)cc[len++]=x%10+'0',x/=10;
	while(len--)putchar(cc[len]);
}
template<typename item>
inline void uprint(register item x){ 
	register int len=0;
	while(x)cc[len++]=x%10+'0',x/=10;
	while(len--)putchar(cc[len]);
}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int N=1<<19;
LL tree[N+N];
int cnt[N+N];
void pu(int now){
	tree[now]=tree[now<<1]+tree[now<<1|1];
	cnt[now]=cnt[now<<1]+cnt[now<<1|1];
}
int lowbound_count(int val,int now=1,int l=1,int r=N+1){
	//<=val
	if(r<=val+1) return cnt[now];
	if(l>val) return 0;
	int mid=(l+r)>>1;
	return lowbound_count(val,now<<1,l,mid)+lowbound_count(val,now<<1|1,mid,r);
}
void add(int pos,LL val){
	//posval
	pos+=N-1;
	cnt[pos]=1;
	tree[pos]=val;
	pos>>=1;
	while(pos){
		pu(pos);
		pos>>=1;
	}
}
void del(int pos){
	pos+=N-1;
	cnt[pos]=0;
	tree[pos]=0;
	pos>>=1;
	while(pos){
		pu(pos);
		pos>>=1;
	}
}
LL getai(int i,int now=1,int l=1,int r=N+1){
	//i
	while(1){
		if(l==r-1){
			return tree[now];
		}
		int mid=(l+r)>>1;
		if(cnt[now<<1]>=i){
			r=mid;
			now=now<<1;
		}
		else{
			i-=cnt[now<<1];
			l=mid;
			now=now<<1|1;
		}
	}
	return 0;
}
LL getpref(int i,int now=1,int l=1,int r=N+1){
	LL ret=0;
	while(1){
		if(l==r-1){
			ret+=tree[now];
			break;
		}
		int mid=(l+r)>>1;
		if(cnt[now<<1]>=i){
			r=mid;
			now=now<<1;
		}
		else{
			ret+=tree[now<<1];
			i-=cnt[now<<1];
			l=mid;
			now=now<<1|1;
		}
	}
	return ret;
}
map<LL,int> M,M2;
int n,q,Cnt;
struct BIT{
	LL bit[N];
	BIT(){memset(bit,0,sizeof(bit));}
	void add(int pos,LL val){
		while(pos<=n+q){
			bit[pos]+=val;
			pos+=pos&-pos;
		}
	}
	LL query(int pos){
		LL ret=0;
		if(pos<0) exit(0);
		while(pos){
			ret+=bit[pos];
			pos^=pos&-pos;
		}
		return ret;
	}
}pre,suf;
struct Id_Tree{
	int tag[N+N];
	LL sum[N+N];
	LL tree[N+N];
	Id_Tree(){memset(tag,0,sizeof(tag));memset(sum,0,sizeof(sum));memset(tree,0,sizeof(tree));}
	inline void pd(int idx){
		tree[idx]+=sum[idx]*tag[idx];
		if(idx<N){
			tag[idx<<1]+=tag[idx];
			tag[idx<<1|1]+=tag[idx];
		}
		tag[idx]=0;
	}
	inline void pu(int idx){
		tree[idx]=tree[idx<<1]+tree[idx<<1|1];
		sum[idx]=sum[idx<<1]+sum[idx<<1|1]; 
	}
	void add(int pos,int inittag,LL val,int now=1,int l=1,int r=N+1){
		while(true){
			if(l==r-1){
				sum[now]=val;
				tree[now]=val*inittag;
				break;
			}
			pd(now<<1);
			pd(now<<1|1);
			int mid=(l+r)>>1;
			if(mid>pos){
				r=mid;
				now=now<<1;
			}
			else{
				l=mid;
				now=now<<1|1;
			}
		}
		pos+=N-1;
		pos>>=1;
		while(pos){
			pu(pos);
			pos>>=1;
		}
	}
	void clear(int pos,int now=1,int l=1,int r=N+1){
		while(true){
			if(l==r-1){
				sum[now]=0;
				tree[now]=0;
				break;
			}
			pd(now<<1);
			pd(now<<1|1);
			int mid=(l+r)>>1;
			if(mid>pos){
				r=mid;
				now=now<<1;
			}
			else{
				l=mid;
				now=now<<1|1;
			}
		}
		pos+=N-1;
		pos>>=1;
		while(pos){
			pu(pos);
			pos>>=1;
		}
	}
	void addtag(int a,int b,int val,int now=1,int l=1,int r=N+1){
		pd(now);
		if(r<=a||l>=b){
			return;
		}
		if(r<=b&&l>=a){
			tag[now]+=val;
			pd(now);
			return ; 
		}
		int mid=(l+r)>>1;
		addtag(a,b,val,now<<1,l,mid);
		addtag(a,b,val,now<<1|1,mid,r);
		pu(now);
	}
	LL query(int pos,int now=1,int l=1,int r=N+1){
		LL ret=0;
		while(true){
			pd(now);
			if(l==r-1){
				ret+=tree[now];	
				break;
			}
			int mid=(l+r)>>1;
			if(mid>pos){
				r=mid;
				now=now<<1;
			}
			else{
				l=mid;
				pd(now<<1);
				ret+=tree[now<<1];
				now=now<<1|1;
			}
		}
		return ret;
	}
}idpre,idsuf;
vector<pair<bool,LL> > v;
void Add(LL val){
	int rnk=lowbound_count(M[val]),now=cnt[1];
	pre.add(M[val],val);
	suf.add(M2[val],val);
	idpre.addtag(M[val],N+1,1);
	idsuf.addtag(M2[val],N+1,1);
	idpre.add(M[val],rnk+1,val);
	idsuf.add(M2[val],now-rnk+1,val);
	add(M[val],val);
}
void Del(LL val){
	pre.add(M[val],-val);
	suf.add(M2[val],-val);
	idpre.clear(M[val]);
	idsuf.clear(M2[val]);
	idpre.addtag(M[val],N+1,-1);
	idsuf.addtag(M2[val],N+1,-1);
	del(M[val]);
}
LL get(int x){
	return tree[1]-getpref(cnt[1]-x)-getpref(x+1);
}
LL prepre(int x){
	//pre[1]+...pre[x]
	if(x==0) return 0;
	LL G=getai(x);
	LL ret=pre.query(M[G])*(x+1);
	ret-=idpre.query(M[G]);	
	return ret;
}
LL sufpre(int x){
	//suf[1]+...suf[x]
	if(x==0) return 0;
	LL G=getai(cnt[1]-x+1);
	LL ret=suf.query(M2[G])*(x+1);
	ret-=idsuf.query(M2[G]);
	return ret;
}
LL Query(int l,int r){
	if(l>r) return 0ll;
	return sufpre(r)-sufpre(l-1)-prepre(r)+prepre(l-1);
}
void Print(){
	int now=cnt[1];
	int l=1;
	l=max(1,(now+1)/2-1);
	LL ret=0;
	if(now==1||get(l)<=0){
		ret=Query(1,now);
	}
	else{
		int L,R;
		L=0,R=l;
		while(L<R-1){
			int mid=(L+R)>>1;
			if(get(l-mid)>0){
				L=mid;
			}
			else{
				R=mid;
			}
		}
		int l_,r_;
		l_=l-L;
		L=0,R=now-l;
		while(L<R-1){
			int mid=(L+R)>>1;
			if(get(l+mid)>0){
				L=mid;
			}
			else{
				R=mid;
			}
		}
		r_=l+L;
		LL A,B;
		l_++,r_++;
		A=getai(r_);
		B=getai(l_);
		ret+=pre.query(M[A])-pre.query(M[B]-1);
		ret+=Query(r_+1,now);
		ret+=Query(1,l_-1);
	}
	print(ret);
}
LL S[N];
int rnk[N],R[N];
bool cmp(int A,int B){
	return S[A]<S[B];
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	read(n);
	read(q);
	rb(i,1,n){
		LL si;
		read(si);
		S[i]=si;
		M[si]=1;
		rnk[i]=i;
	}
	sort(rnk+1,rnk+1+n,cmp);
	rb(i,1,n) R[rnk[i]]=i;
	rb(i,1,q){
		int t;
		LL si;
		read(t);
		read(si);
		M[si]=1;
		if(t==1){
			v.PB(II(1,si));
		}
		else{
			v.PB(II(0,si));
		}
	}
	for(auto ite=M.begin();ite!=M.end();ite++) ite->SEC=++Cnt;
	for(auto ite=M.begin();ite!=M.end();ite++) M2[ite->FIR]=Cnt-(ite->SEC)+1;
	
	rb(i,1,n){
		pre.add(M[S[i]],S[i]);
		suf.add(M2[S[i]],S[i]);
		add(M[S[i]],S[i]);
		idpre.add(M[S[i]],R[i],S[i]);
		idsuf.add(M2[S[i]],n-R[i]+1,S[i]);
	}
	Print();
	putchar('\n');
	for(auto it:v){
		if(it.FIR==1) Add(it.SEC);
		else Del(it.SEC);
		Print();
		putchar('\n');
	}
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}
/*

3 0
1 2 3


5 0
2 5 3 6 7 

*/