#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 1505
const int mod=998244353;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
typedef vector<int> poly;
poly Mul(poly &A,poly &B){
	poly C;
	C.resize(A.size()+B.size()-1);
	for(int i=0;i<(int)A.size();++i){
		for(int j=0;j<(int)B.size();++j){
			C[i+j]=(C[i+j]+1LL*A[i]*B[j])%mod;
		}
	}
	return C;
}
struct Union_Set{
	int f[N],siz[N],edges[N];
	poly A[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			A[i].resize(2);
			A[i][1]=1;
			siz[i]=1;
			f[i]=i; 
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
	inline void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		++edges[fx];
		if(fx^fy){
			A[fx]=Mul(A[fx],A[fy]);
			siz[fx]+=siz[fy];
			edges[fx]+=edges[fy];
			f[fy]=fx;
		}
		if(edges[fx]==siz[fx]*(siz[fx]-1)/2){
			++A[fx][1];
		} 
	}
}S;
int n,tot;
struct Link{
	int x,y,w;
	bool operator <(const Link b)const{
		return w<b.w;
	}
}l[N*N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int x=read();
			if(i<j){
				l[++tot]={i,j,x};
			}
		}
	}
	S.init(n);
	sort(l+1,l+tot+1);
	for(int i=1;i<=tot;++i){
		S.Merge(l[i].x,l[i].y);
	}
	int root=S.getf(1);
	for(int i=1;i<=n;++i){
		printf("%d ",S.A[root][i]);
	}
	return 0;
}