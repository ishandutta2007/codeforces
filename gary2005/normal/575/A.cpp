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
const int MAXN=5e4+233;
LL k;
int n,m,s[MAXN],MOD;
void add(int &A,int B){A+=B;if(A>=MOD){A-=MOD;}}
map<LL,int> pos;
int get(LL _){
	auto ite=pos.find(_);
	if(ite==pos.end()){return s[_%n];}
	return ite->SEC;
}
struct Matrix{
	int a[2][2];
	Matrix () {memset(a,0,sizeof(a));}
	Matrix (int A,int B,int C,int D) {a[0][0]=A,a[0][1]=B,a[1][0]=C,a[1][1]=D;}
	Matrix operator * (Matrix oth){
		Matrix ret;
		rep(i,2) rep(j,2) rep(k,2) add(ret.a[i][j],1ll*a[i][k]*oth.a[k][j]%MOD);
		return ret;
	}
	Matrix operator ^ (LL B){
		if(B==0){
			return Matrix (1,0,0,1);
		}
		Matrix tmp=(*this)^(B>>1);
		tmp=tmp*tmp;
		if(B&1){
			tmp=tmp*(*this);
		}
		return tmp;
	}
	void print(){
		rep(i,2){
			rep(j,2){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
Matrix tran[MAXN];
Matrix pre[MAXN],suf[MAXN];
Matrix bz[MAXN][16];
int lg[1<<16];
Matrix G(LL _){
	return Matrix(0,get(_-2),1,get(_-1));
}
Matrix Get(int st,int len){
	Matrix tmp=Matrix(1,0,0,1);
	while(len){
		int lb=(len&(-len));
		tmp=tmp*bz[st][lg[lb]];
		st+=lb;
		len^=lb;
	}
	return tmp;
}
Matrix shit(LL l,LL r){
	if(l==r) return G(l);
	Matrix tmp(1,0,0,1);
	int z=r%n+1;
	if(r-l+1<=z){
		r%=n;
		l%=n;
		return Get(l,r-l+1);
	}
	else{
		Matrix fin=pre[z-1];
		int y=(n-l%n)%n;
		Matrix fii=(y==0? Matrix(1,0,0,1):suf[n-y]);
		LL t=(r-l+1)-z-y;
		if(t%n!=0) cout<<"No"<<endl;
		return fii*(pre[n-1]^(t/n))*fin;
	}
}
int main(){//575A
	scanf("%lld%d",&k,&MOD);
	if(k==0){
		cout<<0<<endl;
		return 0;
	}
	if(k==1){
		cout<<1%MOD<<endl;
		return 0;
	}
	scanf("%d",&n);
	rep(i,n) scanf("%d",&s[i]),s[i]%=MOD;
	rep(i,n){
		int pre,prepre;
		pre=get((i-1+n+n)%n);
		prepre=get((i-2+n+n)%n);
		tran[i]=Matrix(0,prepre,1,pre);
	}
	rep(i,n){
		if(!i) pre[0]=tran[0];
		else pre[i]=pre[i-1]*tran[i];
	}
	rl(i,n-1,0){
		if(i==n-1) suf[i]=tran[i];
		else suf[i]=tran[i]*suf[i+1];
	}
	rep(i,n) bz[i][0]=tran[i];
	rb(i,1,15)
		for(int j=0;j-1<n-(1<<i);++j){
			bz[j][i]=bz[j][i-1]*bz[j+(1<<(i-1))][i-1];
		}
	rep(i,16) lg[1<<i]=i; 
	scanf("%d",&m);
	vector<LL> fu;
	rb(i,1,m){
		LL j;
		int v;
		scanf("%lld%d",&j,&v);
		v%=MOD;
		pos[j]=v;
		fu.PB(j+1);
		fu.PB(j+2);
	}
	fu.PB(2);
	fu.PB(k);
	sort(ALL(fu));
	fu.erase(unique(ALL(fu)),fu.end());
	vector<pair<LL,LL> > seg;
	LL lst=0;
	for(auto it:fu){
		if(it<2) continue;
		if(lst!=0&&it-1>=lst){
			seg.PB({lst,it-1});
		}
		seg.PB({it,it});
		lst=it+1;
		if(it==k) break;
	}
	Matrix ret(1,0,0,1);
	for(auto it:seg){
		ret=ret*shit(it.FIR,it.SEC);
	}
	cout<<ret.a[1][1]<<endl;
	return 0;
}
/*

10 888888
3
1 2 1
2
7 3
5 4

0 213845
4
5 4 123 4
1
8 6


*/