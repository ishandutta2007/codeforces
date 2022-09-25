#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
int n,m,Q,a0[N],a1[N],b0[N],b1[N];
void Get(int *a){
	static char s[N];
	cin>>(s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;++i){
		a[i]=s[i]=='R';
	}
}
struct Matrix{
	int g[2][2];
	Matrix(){memset(g,0x3f,sizeof(g));}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix c;
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				c.g[i][j]=min(a.g[i][0]+b.g[0][j],a.g[i][1]+b.g[1][j]);
			}
		}
		return c;
	}
};
class Segment_Tree{
	int n,m,a0[N],a1[N];
	struct node{
		Matrix M[2][2];
		int rev0,rev1,sum0,sum1,len;
		void Rev0(){
			rev0^=1;
			sum0=len-sum0;
			swap(M[0][0],M[1][0]);
			swap(M[0][1],M[1][1]);
		}
		void Rev1(){
			rev1^=1;
			sum1=len-sum1;
			swap(M[0][0],M[0][1]);
			swap(M[1][0],M[1][1]);
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	Matrix pre,suf;
	inline void update(int u){
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				t[u].M[i][j]=t[ls].M[i][j]*t[rs].M[i][j];
			}
		}
		t[u].sum0=t[ls].sum0+t[rs].sum0;
		t[u].sum1=t[ls].sum1+t[rs].sum1;
	}
	void pushdown(int u){
		if(t[u].rev0){
			t[ls].Rev0();
			t[rs].Rev0();
			t[u].rev0=0;
		}
		if(t[u].rev1){
			t[ls].Rev1();
			t[rs].Rev1();
			t[u].rev1=0;
		}
	}
	
public:
	void build(int u,int L,int R){
		t[u].len=R-L+1;
		if(L==R){
			t[u].sum0=a0[L];
			t[u].sum1=a1[L];
			for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
					t[u].M[i][j].g[0][0]=(a0[L]^i)+(a1[L]^j);
					t[u].M[i][j].g[1][0]=(a0[L]^i)+(a1[L]^j)+m;
					t[u].M[i][j].g[0][1]=(a0[L]^i^1)+(a1[L]^j^1)+m;
					t[u].M[i][j].g[1][1]=(a0[L]^i^1)+(a1[L]^j^1);
				}	
			}
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void init(int *_a0,int *_a1,int _n,int _m){
		n=_n,m=_m;
		for(int i=1;i<=n;++i){
			a0[i]=_a0[i],a1[i]=_a1[i];	
		}
		build(1,1,n);
	}
	void Change(pii p){
		pre.g[0][0]=p.first;
		pre.g[1][1]=m-p.first;
		suf.g[0][0]=p.second;
		suf.g[1][1]=m-p.second;
	}
	void Reverse(int u,int L,int R,int l,int r,int op){
		if(L>=l&&R<=r){
			op?t[u].Rev1():t[u].Rev0();
			return;	
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Reverse(ls,L,mid,l,r,op);
		if(r>mid)Reverse(rs,mid+1,R,l,r,op);
		update(u);
	}
	int get_ans(){
		Matrix jb;
		jb.g[0][0]=jb.g[0][1]=0;
		Matrix ans=jb*pre*t[1].M[0][0]*suf;
		return min(ans.g[0][0],ans.g[0][1]);
	}
	pii get_sum(){
		return make_pair(t[1].sum0,t[1].sum1);
	}
}T1,T2;
int MYHMD(){
	return min(T1.get_ans(),T2.get_ans());	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>Q;
	Get(a0),Get(a1);
	Get(b0),Get(b1);
	T1.init(a0,a1,n,m);
	T2.init(b0,b1,m,n);
	T1.Change(T2.get_sum());
	T2.Change(T1.get_sum());
	cout<<MYHMD()<<'\n';
	while(Q--){
		char c;
		int l,r;
		cin>>c>>l>>r;
		if(c=='U'){
			T2.Reverse(1,1,m,l,r,0);
			T1.Change(T2.get_sum());	
		}
		else if(c=='D'){
			T2.Reverse(1,1,m,l,r,1);
			T1.Change(T2.get_sum());	
		}
		else if(c=='L'){
			T1.Reverse(1,1,n,l,r,0);
			T2.Change(T1.get_sum());	
		}
		else if(c=='R'){
			T1.Reverse(1,1,n,l,r,1);
			T2.Change(T1.get_sum());	
		}
		cout<<MYHMD()<<'\n';
	}
	return 0;
}