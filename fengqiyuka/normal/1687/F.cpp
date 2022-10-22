#include<bits/stdc++.h>
#define Low(x) pow(2,(int)(log(x-0.1)/log(2))+1)
using namespace std;

typedef long long ll;
const int mod=998244353,N=250100,maxn=250001,o=3; 
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
}
using namespace polynomial;

int fl[N],nf[N],n,s;
poly A[N][2][2],B[N][2][2],C[N][2][2],AA[2][2],BB[2][2],CC[2][2],A1,B1,A2,B2;

void solve(int l,int r){
	//care!!!
	if(l==r){
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++){
				A[l][i][j].a.resize(2);
				B[l][i][j].a.resize(2);
				C[l][i][j].a.resize(2);
			}
		int t=ni(l);
		A[l][0][0].a[0]=A[l][0][1].a[0]=(ll)(mod-l+1)*t%mod;
		A[l][0][0].a[1]=A[l][0][1].a[1]=mod-t;
		A[l][1][1].a[1]=1;
		for(int i=0;i<=1;i++)
			for(int j=0;j<=1;j++)
				for(int k=0;k<=1;k++){
					B[l][i][j].a[k]=(ll)A[l][i][j].a[k]*A1.a[l]%mod;
					if(l<n) C[l][i][j].a[k]=(ll)A[l][i][j].a[k]*A2.a[l]%mod;
				}
		return ;
	}
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	
	int len=Low(r-l+2);
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++){
			A[l][i][j].DFT(len,0);
			B[l][i][j].DFT(len,0);
			C[l][i][j].DFT(len,0);
			A[mid+1][i][j].DFT(len,0);
			B[mid+1][i][j].DFT(len,0);
			C[mid+1][i][j].DFT(len,0);
			AA[i][j].a.resize(len);
			BB[i][j].a.resize(len);
			CC[i][j].a.resize(len);
			for(int p=0;p<len;p++){
				AA[i][j].a[p]=BB[i][j].a[p]=CC[i][j].a[p]=0;
			}
		}
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++){
			for(int k=0;k<=1;k++)
				for(int p=0;p<len;p++){
					AA[i][k].a[p]=(AA[i][k].a[p]+(ll)A[l][i][j].a[p]*A[mid+1][j][k].a[p])%mod;
					BB[i][k].a[p]=(BB[i][k].a[p]+(ll)A[l][i][j].a[p]*B[mid+1][j][k].a[p])%mod;
					CC[i][k].a[p]=(CC[i][k].a[p]+(ll)A[l][i][j].a[p]*C[mid+1][j][k].a[p])%mod;
				}
			for(int p=0;p<len;p++){
				BB[i][j].a[p]=(BB[i][j].a[p]+B[l][i][j].a[p])%mod;
				CC[i][j].a[p]=(CC[i][j].a[p]+C[l][i][j].a[p])%mod;
			}
		}
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			for(int p=0;p<len;p++){
				A[l][i][j].a[p]=AA[i][j].a[p];
				B[l][i][j].a[p]=BB[i][j].a[p];
				C[l][i][j].a[p]=CC[i][j].a[p];
			}
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++){
			A[l][i][j].DFT(len,1);
			B[l][i][j].DFT(len,1);
			C[l][i][j].DFT(len,1);
		}
}

int C1(int n,int m){
	if(n<m) return 0;
	return (ll)fl[n]*nf[m]%mod*nf[n-m]%mod;
}

int main()
{
	
	fl[0]=1;for(int i=1;i<=maxn;i++) fl[i]=(ll)fl[i-1]*i%mod;
	nf[maxn]=ni(fl[maxn]);for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(i+1)%mod;
	
	scanf("%d%d",&n,&s);
	
	n=n-s;
	A1.a.resize(n+1);B1.a.resize(n+1);
	A2.a.resize(n);B2.a.resize(n);
	
	for(int i=0;i<=n;i++){
		A1.a[i]=(ll)mi(i,n)*nf[i]%mod;
		if(i%2==0) B1.a[i]=nf[i];
		else B1.a[i]=mod-nf[i];
	}
	A1=A1*B1;
	
	for(int i=0;i<n;i++){
		A2.a[i]=(ll)mi(i,n-1)*nf[i]%mod;
		if(i%2==0) B2.a[i]=nf[i];
		else B2.a[i]=mod-nf[i];
	}
	A2=A2*B2;
	
	for(int i=0;i<=n;i++){
		A1.a[i]=(ll)A1.a[i]*fl[i]%mod*nf[n]%mod;
		if(i<n) A2.a[i]=(ll)A2.a[i]*fl[i]%mod*nf[n-1]%mod;
	}
	
	solve(1,n);
	
	for(int i=0;i<=n;i++){
		B[1][0][1].a[i]=(B[1][0][1].a[i]+A1.a[i])%mod;
		if(i<n) C[1][0][1].a[i]=(C[1][0][1].a[i]+A2.a[i])%mod;
	}
	
	poly G,H,P;
	P.a.resize(n+1);
	for(int i=0;i<=n;i++) P.a[i]=nf[i];
	int tt=C[1][0][1].a[0];C[1][0][1].a[0]=0;
	C[1][0][1].a.resize(n+1);
	for(int i=1;i<=n;i++) C[1][0][1].a[i]=(ll)C[1][0][1].a[i]*nf[i-1]%mod;
	G=C[1][0][1]*P;
	for(int i=1;i<=n;i++) G.a[i]=(ll)G.a[i]*fl[i-1]%mod;
	G.a[0]=tt;
	
	tt=B[1][0][1].a[0];B[1][0][1].a[0]=0;
	B[1][0][1].a.resize(n+1);
	for(int i=1;i<=n;i++) B[1][0][1].a[i]=(ll)B[1][0][1].a[i]*nf[i-1]%mod;
	H=B[1][0][1]*P;
	for(int i=1;i<=n;i++) H.a[i]=(ll)H.a[i]*fl[i-1]%mod;
	H.a[0]=tt;
	
	poly D;D.a.resize(n+1);
	for(int i=0;i<=n;i++) D.a[i]=1;
	D=D*G;
	for(int i=0;i<H.a.size();i++) H.a[i]=(ll)H.a[i]*n%mod;
	
	for(int i=0;i<=n;i++) D.a[i]=(D.a[i]+H.a[i])%mod;
	
	poly E;E.a.resize(n+1);
	for(int i=0;i<=n;i++){
		if(i%2==0) E.a[i]=C1(n+1,i);
		else E.a[i]=mod-C1(n+1,i);
	}
	
	E=E*D;
	for(int i=1;i<n;i++) E.a[i]=(E.a[i]+E.a[i-1])%mod;
	for(int i=0;i<s;i++) printf("0 ");
	for(int i=0;i<n;i++){
		int t=(ll)fl[n-1]*E.a[n-1-i]%mod*C1(n-1+s,s)%mod;
		printf("%d ",t);
	}
	
	printf("\n");
	
	return 0;
}