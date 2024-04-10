#include<bits/stdc++.h>
//#pragma GCC optimize(2)
#define Low(x) pow(2,(int)(log(x-0.1)/log(2))+1)
using namespace std;

const int N=1e5+100,maxn=1e5;
int fl[N],nf[N];

typedef long long ll;
const int mod=998244353,o=3;
int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}

int mymax(int x,int y) {return (x>y?x:y);}

inline void add(int &x){
	x+=(x>>31)&mod;
}

namespace polynomial{
	vector<int> g,O(1);
	struct poly{
		vector<int> a;
		void DFT(int len,int ty){
			a.resize(len);
			if(g.size()<len){
				g.resize(len);
				while(O.size()<=len){
					int one=mi(o,(mod-1)/O.size());
					int t=O.size(),tt=1;
					for(int j=0;j<t;j++){
						O.push_back(tt);
						tt=(ll)tt*one%mod;
					}
				}
			}
			if(ty) for(int i=1;i<len/2;i++) swap(a[i],a[len-i]);
			for(int i=0;i<len;i++){
				g[i]=g[i/2]/2+(len/2)*(i&1);
				if(i<g[i]) swap(a[i],a[g[i]]);
			}
			
			int *b=a.data(),*st=O.data();
			for(int i=2;i<=len;i*=2){
				for(int *j=b;j!=b+len;j+=i){
					for(int *t2=j,*t3=j+i/2,*t=st+i;t2!=j+i/2;t2++,t3++,t++){
						int tmp=(ll)*t3**t%mod;
						add(*t3=*t2-tmp);
						add(*t2+=tmp-mod);
					}
				}
			}
			if(ty){
				int Nlen=ni(len);
				for(int i=0;i<len;i++) a[i]=(ll)a[i]*Nlen%mod;
			}
		}
	};
	
	poly operator + (poly A,poly B){
		int len=mymax(A.a.size(),B.a.size());
		A.a.resize(len);B.a.resize(len);
		for(int i=0;i<len;i++) A.a[i]=(A.a[i]+B.a[i])%mod;
		return A;
	}
	
	poly operator * (poly A,poly B){
		int len=Low(A.a.size()+B.a.size()-1);
		A.DFT(len,0);B.DFT(len,0);
		for(int i=0;i<len;i++) A.a[i]=(ll)A.a[i]*B.a[i]%mod;
		A.DFT(len,1);
		return A;
	}
	
	poly Inv(poly A){
		poly B;B.a.resize(1);
		B.a[0]=ni(A.a[0]);
		int len=Low(A.a.size());
		for(int i=2;i<=len;i*=2){
			poly C;C.a=A.a;C.a.resize(i);
			B.DFT(i*2,0);C.DFT(2*i,0);
			for(int j=0;j<i*2;j++) B.a[j]=((ll)2*B.a[j]-(ll)C.a[j]*B.a[j]%mod*B.a[j]%mod+mod)%mod;
			B.DFT(i*2,1);B.a.resize(i);
		}
		return B;
	}
	
	poly operator % (poly A,poly B){
		while(A.a.size()>1&&A.a.back()==0) A.a.pop_back();
		while(B.a.size()>1&&B.a.back()==0) B.a.pop_back();
		if(A.a.size()<B.a.size()) return A;
		int t1=A.a.size(),t2=B.a.size();
		for(int i=0;i<t1/2;i++) swap(A.a[i],A.a[t1-1-i]);
		for(int i=0;i<t2/2;i++) swap(B.a[i],B.a[t2-1-i]);
		
		B.a.resize(t1);
		poly C=Inv(B)*A;
		B.a.resize(t2);C.a.resize(t1-t2+1);
		C=B*C;
		for(int i=0;i<t1;i++) C.a[i]=(A.a[i]-C.a[i]+mod)%mod;
		for(int i=0;i<t1/2;i++) swap(C.a[i],C.a[t1-1-i]);
		C.a.resize(t2-1);
		return C;
	}
	
	poly mul(poly A,poly B){
		int t1=A.a.size(),t2=B.a.size();
		for(int i=0;i<t2/2;i++) swap(B.a[i],B.a[t2-1-i]);
		A=A*B;
		for(int i=t2-1;i<A.a.size();i++) A.a[i-t2+1]=A.a[i];
		A.a.resize(t1);
		return A;
	}
	
}
using namespace polynomial;

int a[N],n,K,P,b[N],c[N],h[N],d[N];

void solve(int l,int r){
	if(l==r){
		b[l]=(ll)(b[l]+1)*P%mod*ni(1-P+mod)%mod;
		return ;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	
	poly A,B;
	A.a.resize(mid-l+1);
	B.a.resize(r-l+1);
	for(int i=l;i<=mid;i++) A.a[i-l]=(ll)b[i]*nf[i]%mod;
	for(int i=0;i<=r-l;i++) B.a[i]=nf[i];
	A=A*B;
	for(int i=mid+1;i<=r;i++) b[i]=(b[i]+(ll)fl[i]*A.a[i-l])%mod;
	
	solve(mid+1,r);
}

poly f[N][20],w[N][20],p[N];
void solve1(int l,int r,int dep){
	if(l==r){
		f[l][dep].a.resize(2);
		f[l][dep].a[0]=1;
		f[l][dep].a[1]=mod-a[l];
		return ;
	}
	int mid=(l+r)>>1;
	solve1(l,mid,dep+1);solve1(mid+1,r,dep+1);
	f[l][dep]=f[l][dep+1]*f[mid+1][dep+1];
}

void solve2(int l,int r,int dep){
	if(l==r){
		d[l]=p[l].a[0];
		return ;
	}
	int mid=(l+r)>>1;
	
	int len=Low(p[l].a.size())*2;
	p[l].DFT(len,0);
	
	int t1=f[l][dep+1].a.size(),t2=f[mid+1][dep+1].a.size();
	for(int i=0;i<t1/2;i++) swap(f[l][dep+1].a[i],f[l][dep+1].a[t1-1-i]);
	for(int i=0;i<t2/2;i++) swap(f[mid+1][dep+1].a[i],f[mid+1][dep+1].a[t2-1-i]);
	
	f[l][dep+1].DFT(len,0);
	f[mid+1][dep+1].DFT(len,0);
	
	p[mid+1].a.resize(len);
	for(int i=0;i<len;i++){
		p[mid+1].a[i]=(ll)f[l][dep+1].a[i]*p[l].a[i]%mod;
		p[l].a[i]=(ll)f[mid+1][dep+1].a[i]*p[l].a[i]%mod;
	}
	
	p[l].DFT(len,1);
	p[mid+1].DFT(len,1);
	
	for(int i=t2-1;i<len;i++) p[l].a[i-t2+1]=p[l].a[i];
	for(int i=t1-1;i<len;i++) p[mid+1].a[i-t1+1]=p[mid+1].a[i];
	
	p[l].a.resize(mid-l+1);
	p[mid+1].a.resize(r-mid);
	
	solve2(l,mid,dep+1);solve2(mid+1,r,dep+1);
}

void solve3(int l,int r,int dep){
	if(l==r){
		w[l][dep].a.resize(1);
		w[l][dep].a[0]=c[l];
		return ;
	}
	int mid=(l+r)>>1;
	solve3(l,mid,dep+1);solve3(mid+1,r,dep+1);
	w[l][dep]=w[l][dep+1]*f[mid+1][dep+1]+f[l][dep+1]*w[mid+1][dep+1];
}

poly Ans[N][20][2][2][2];
void solve4(int l,int r,int dep){
	if(l==r){
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++){
				int t=1;
				if(i) t=(ll)t*l%mod;
				if(j) t=(ll)t*(n-l+1)%mod;
				Ans[l][dep][0][i][j].a={0,(int)((ll)a[l]*t%mod)};
				Ans[l][dep][1][i][j].a={0,(int)((ll)d[l]*t%mod)};
			}
		Ans[l][dep][0][0][0].a[0]=1;
		return ;
	}
	int mid=(l+r)>>1;
	solve4(l,mid,dep+1);solve4(mid+1,r,dep+1);
	
	int len=Low(r-l+2);
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++){
				Ans[l][dep+1][i][j][k].DFT(len,0);
				Ans[mid+1][dep+1][i][j][k].DFT(len,0);
				Ans[l][dep][i][j][k].a.resize(len);
			}
	
	for(int k=0;k<len;k++){
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++){
				Ans[l][dep][0][i][j].a[k]=(Ans[l][dep][0][i][j].a[k]+(ll)Ans[l][dep+1][0][i][0].a[k]*Ans[mid+1][dep+1][0][0][j].a[k])%mod;
				Ans[l][dep][1][i][j].a[k]=(Ans[l][dep][1][i][j].a[k]+(ll)Ans[l][dep+1][0][i][0].a[k]*Ans[mid+1][dep+1][1][0][j].a[k])%mod;
				Ans[l][dep][1][i][j].a[k]=(Ans[l][dep][1][i][j].a[k]+(ll)Ans[l][dep+1][1][i][0].a[k]*Ans[mid+1][dep+1][0][0][j].a[k])%mod;
				if(i){
					Ans[l][dep][0][i][j].a[k]=(Ans[l][dep][0][i][j].a[k]+Ans[mid+1][dep+1][0][i][j].a[k])%mod;
					Ans[l][dep][1][i][j].a[k]=(Ans[l][dep][1][i][j].a[k]+Ans[mid+1][dep+1][1][i][j].a[k])%mod;
				}
				if(j){
					Ans[l][dep][0][i][j].a[k]=(Ans[l][dep][0][i][j].a[k]+Ans[l][dep+1][0][i][j].a[k])%mod;
					Ans[l][dep][1][i][j].a[k]=(Ans[l][dep][1][i][j].a[k]+Ans[l][dep+1][1][i][j].a[k])%mod;
				}
			}
	}
	
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)
				Ans[l][dep][i][j][k].DFT(len,1);
}

int a1[N],a2[N],b1[N],b2[N];

int main()
{
	
	fl[0]=1;for(int i=1;i<=maxn;i++) fl[i]=(ll)fl[i-1]*i%mod;
	nf[maxn]=ni(fl[maxn]);for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(i+1)%mod;
	
	scanf("%d%d%d",&n,&K,&P);
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	solve(0,K);
	
	solve1(1,n,0);
	
	poly A;A.a.resize(K+1);
	for(int i=1;i<=K;i++) A.a[i]=(ll)nf[i]*P%mod*ni(P-1)%mod;
	A.a[0]=1;
	A=Inv(A);
	for(int i=0;i<=K;i++) A.a[i]=(ll)A.a[i]*fl[K]%mod*nf[K-i]%mod;
	for(int i=0;i<=K/2;i++) swap(A.a[i],A.a[K-i]);
	for(int i=0;i<=K;i++) A.a[i]=(ll)A.a[i]*ni(P-1)%mod;
	A.a[K]=(ll)A.a[K]*P%mod;
	
	p[1].a.resize(K+1);
	for(int i=0;i<=K;i++) p[1].a[i]=A.a[i];
	
	f[1][0].a.resize(K+1);
	poly D=Inv(f[1][0]);D.a.resize(K+1);
	p[1]=mul(p[1],D);p[1].a.resize(n);
	
	solve2(1,n,0);
	
	for(int i=1;i<=n;i++) d[i]=((ll)d[i]*mi(P,a[i])+b[K])%mod;
	
	a1[0]=1;
	for(int i=1;i<=n;i++){
		a1[i]=((ll)a1[i-1]*(a[i]+1)+1)%mod;
		a2[i]=((ll)a2[i-1]*(a[i]+1)+(ll)a1[i-1]*a[i])%mod;
	}
	
	b1[n+1]=1;
	for(int i=n;i>=1;i--){
		b1[i]=((ll)b1[i+1]*(a[i]+1)+1)%mod;
		b2[i]=((ll)b2[i+1]*(a[i]+1)+(ll)b1[i+1]*a[i])%mod;
	}
	
	
//	solve4(1,n,0);
	
	int Ans2=0;
//	for(int i=1;i<=n;i++)
//		Ans2=(Ans2+(ll)Ans[1][0][1][1][1].a[i]*i)%mod;
	
	for(int i=1;i<=n;i++) Ans2=(Ans2+((ll)a1[i-1]*b1[i+1]+(ll)a1[i-1]*b2[i+1]+(ll)a2[i-1]*b1[i+1])%mod*d[i])%mod;
	
	printf("%d\n",Ans2);
	
	return 0;
}