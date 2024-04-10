#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int w[8];
int ways[8][1<<7][1<<7];

struct Matrix{
	int sz;
	long long a[128][128];
} M[8];
Matrix unity;

Matrix mult(Matrix A, Matrix B){
	Matrix C;
	C.sz=A.sz;
	for(int i=0; i < B.sz; ++i)
		for(int j=0; j < B.sz; ++j){
			C.a[i][j]=0;
			for(int k=0; k < B.sz; ++k)
				C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%MOD;
		}
	return C;
}

int main(){
	for(int i=1; i <= 7; ++i)
		scanf("%d", w+i);
	for(int i=1; i <= 7; ++i){
		M[i].sz=(1<<i);
		for(int a=0; a < (1<<i); ++a)
			for(int c=0; c < (1<<i); ++c){
				ways[i][a][c]=0;
				for(int b=0; b < (2<<i); ++b){
					if(!(b&1))
						continue;
					if(b < (1<<i))
						continue;
					bool ok=1;
					for(int j=0; j < i; ++j){
						if(!(b&(1<<j)))
							continue;
						if(!(b&(2<<j)))
							continue;
						if(!(a&(1<<j)))
							continue;
						if(!(c&(1<<j)))
							continue;
						ok=0;
					}
					ways[i][a][c] += ok;
				}
				M[i].a[a][c]=ways[i][a][c];
			}
	}
	for(int i=0; i < 128; ++i)
		unity.a[i][i]=1;
	unity.sz=128;
	int f=-1, l;
	for(int i=1; i <= 7; ++i){
		if(w[i]){
		if(f == -1)f=i;
		l=i;
		for(int j=0; j < 20; ++j){
			if(w[i]&(1<<j))
				unity=mult(unity, M[i]);
			M[i]=mult(M[i], M[i]);
		}
		}
		if(i < 7)
			for(int j=0; j < 128; ++j)
				for(int k=0; k < (1<<i); ++k){
					unity.a[j][k+(1<<i)]=unity.a[j][k];
					unity.a[j][k]=0;
				}
	}
	int ans=unity.a[1][127];
	printf("%d\n", ans);
}