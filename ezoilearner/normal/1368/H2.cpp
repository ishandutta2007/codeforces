#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
 
typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second
 
inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}
 
#define Maxn 200010

int n,m,q;

struct Matrix{
	int a[2][2];
	Matrix(){memset(a,63,sizeof a);}
	Matrix operator*(const Matrix&other){
		Matrix res;
		rep(i,0,1)rep(j,0,1)rep(k,0,1)
			res.a[i][j]=min(res.a[i][j],a[i][k]+other.a[k][j]);
		return res;
	}
};

struct solver{
	int n,m;char s1[Maxn],s2[Maxn];
	Matrix get(int x,int y){
		Matrix res;
		res.a[0][0]=x+y,res.a[0][1]=m+2-x-y;
		res.a[1][0]=m+x+y,res.a[1][1]=2-x-y;
		return res;
	}
	struct Node{Matrix v[2][2];int tag1,tag2,s1,s2;}s[Maxn<<2];
	void tag1(int x,int l,int r){
		swap(s[x].v[0][0],s[x].v[1][0]);
		swap(s[x].v[0][1],s[x].v[1][1]);
		s[x].s1=r-l+1-s[x].s1,s[x].tag1^=1;
	}
	void tag2(int x,int l,int r){
		swap(s[x].v[0][0],s[x].v[0][1]);
		swap(s[x].v[1][0],s[x].v[1][1]);
		s[x].s2=r-l+1-s[x].s2,s[x].tag2^=1;
	}
	void pushup(int x){
		rep(a,0,1)rep(b,0,1)
			s[x].v[a][b]=s[x<<1].v[a][b]*s[x<<1|1].v[a][b];
		s[x].s1=s[x<<1].s1+s[x<<1|1].s1;
		s[x].s2=s[x<<1].s2+s[x<<1|1].s2;
	}
	void pushdown(int x,int l,int r){
		int mid=l+r>>1;
		if(s[x].tag1)tag1(x<<1,l,mid),tag1(x<<1|1,mid+1,r),s[x].tag1=0;
		if(s[x].tag2)tag2(x<<1,l,mid),tag2(x<<1|1,mid+1,r),s[x].tag2=0;
	}
	void build(int x,int l,int r){
		if(l==r){
			rep(a,0,1)rep(b,0,1)
				s[x].v[a][b]=get((s1[l]=='B')^a,(s2[l]=='B')^b);
			s[x].s1=(s1[l]=='B'),s[x].s2=(s2[l]=='B');
			return;
		}
		int mid=l+r>>1;
		build(x<<1,l,mid),build(x<<1|1,mid+1,r);
		pushup(x);
	}
	void update(int x,int l,int r,int L,int R,int v){
		if(L<=l&&R>=r)return(v==1?tag1(x,l,r):tag2(x,l,r)),void();
		int mid=l+r>>1;pushdown(x,l,r);
		if(L<=mid)update(x<<1,l,mid,L,R,v);
		if(R>mid)update(x<<1|1,mid+1,r,L,R,v);
		pushup(x);
	}
	Matrix query(){return s[1].v[0][0];}
	int ask1(){return s[1].s1;}
	int ask2(){return s[1].s2;}
	void init(){build(1,1,n);}
}R,C;

int calc(){
	Matrix m1=R.query(),m2=C.query();int ans=1e9;
	rep(i,0,1)rep(j,0,1){
		ans=min(ans,m1.a[i][j]+(i?m-C.ask1():C.ask1())+(j?m-C.ask2():C.ask2()));
		ans=min(ans,m2.a[i][j]+(i?n-R.ask1():R.ask1())+(j?n-R.ask2():R.ask2()));
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>q>>R.s1+1>>R.s2+1>>C.s1+1>>C.s2+1;
	R.n=C.m=n,R.m=C.n=m;
	R.init(),C.init(),cout<<calc()<<'\n';
	while(q--){
		char ch;int l,r;
		cin>>ch>>l>>r;
		if(ch=='L')R.update(1,1,R.n,l,r,1);
		if(ch=='R')R.update(1,1,R.n,l,r,2);
		if(ch=='U')C.update(1,1,C.n,l,r,1);
		if(ch=='D')C.update(1,1,C.n,l,r,2);
		cout<<calc()<<'\n';
	}
	return 0;
}