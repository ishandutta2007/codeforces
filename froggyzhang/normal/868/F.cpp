#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 100010
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
int n,k,a[N],c[N],l,r;
ll dp[21][N],now;
inline void Del(int x){
	now-=--c[a[x]];
}
inline void Add(int x){
	now+=c[a[x]]++;
} 
inline ll calc(int ql,int qr){
	while(l<ql)Del(l++);
	while(l>ql)Add(--l);
	while(r<qr)Add(++r);
	while(r>qr)Del(r--);
	return now;
}
void Solve(int l,int r,int ql,int qr,ll *f,ll *g){
	if(l>r)return;
	int mid=(l+r)>>1,pos=ql;
	for(int i=min(qr,mid-1);i>=ql;--i){
		ll tmp=g[i]+calc(i+1,mid);
		if(f[mid]>tmp){
			f[mid]=tmp,pos=i;
		}
	}
	Solve(l,mid-1,ql,pos,f,g);
	Solve(mid+1,r,pos,qr,f,g);
}
int main(){
	n=read(),k=read();
	l=1;
	for(int i=1;i<=n;++i)a[i]=read();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=k;++i){
		Solve(1,n,0,n-1,dp[i],dp[i-1]);
	}
	printf("%lld\n",dp[k][n]);
	return 0;
}