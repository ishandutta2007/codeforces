#include <bits/stdc++.h>
#define maxn 100005
#define ll long long

const double eps = 1e-14;

int n,rk[maxn],hull[maxn],tl;
ll t;
double p[maxn],g[maxn],a[maxn],b[maxn],M;

struct Matrix {
	double A[4][4];
	int r,c;
	Matrix (int r1=0,int c1=0){
		std::memset(A,0,sizeof(A));
		r=r1;c=c1;
	}
};

Matrix B[40];

Matrix mul(Matrix A,Matrix B){
	Matrix C = Matrix(A.r,B.c);
	for(int i=1;i<=A.r;++i)
	for(int j=1;j<=A.c;++j)
	for(int k=1;k<=B.c;++k)
		C.A[i][k]+=A.A[i][j]*B.A[j][k];
	return C;
}

Matrix build(int x){
	Matrix A = Matrix(3,3);
	A.A[1][1]=1-p[x];A.A[2][1]=p[x]*M;A.A[2][2]=A.A[3][3]=A.A[3][2]=1;
	A.A[3][1]=g[x];
	return A;
}

double get(double s,int x){
	return p[x]*s+g[x];
}

int cmp(int a,int b){
	if(fabs(p[a]-p[b])<eps) return g[a]>g[b];
	return p[a]<p[b];
}

int main(){
	scanf("%d%lld",&n,&t);
	for(int i=1;i<=n;++i){
		scanf("%lf%lf%lf",&a[i],&b[i],&p[i]);
		g[i] = a[i] * p[i];
		rk[i]=i;
		M=std::max(M,p[i]*b[i]);
	}std::sort(rk+1,rk+n+1,cmp);
	
	for(int j=1;j<=n;++j){
		int i=rk[j];
		if(fabs(p[rk[j]]-p[rk[j-1]])<eps)continue;
		if(tl<2)hull[++tl]=i;
		else {
			while ( (g[i]-g[hull[tl]]) * (p[hull[tl]]-p[hull[tl-1]]) > 
			(g[hull[tl]]-g[hull[tl-1]]) * (p[i]-p[hull[tl]]) ) tl--;
			hull[++tl]=i;
		}
		
	}

	ll cur = 0;
	int p1 = 1;
	double cur_pt = 0;
	
	Matrix F = Matrix(1,3);
	F.A[1][2]=0;F.A[1][3]=1;
	
	while (1) {
		while(p1<tl && g[hull[p1+1]]-g[hull[p1]] > -cur_pt * (p[hull[p1+1]] - p[hull[p1]]))
			 p1++;

		Matrix G = build(hull[p1]);
		B[0]=G;
		
		for(int i=1;i<=34;++i)B[i]=mul(B[i-1],B[i-1]);
		
		for(int i=34;i>=0;i--){
			if (cur + (1ll<<i) >= t) continue;
			Matrix N = mul(F,B[i]);
			double new_pt = -N.A[1][1]+N.A[1][2]*M ;
			
			if (p1 == tl || get(new_pt, hull[p1]) > get(new_pt, hull[p1+1])) {
				F = N;
				cur += (1ll<<i);
				
			}
		} 
		
		F = mul(F,B[0]); 
		
		cur ++;
		
		cur_pt = -F.A[1][1] + F.A[1][2]*M;
		
		if (cur == t) break;
	}
	printf("%.8f", F.A[1][1]);
	return 0;
}