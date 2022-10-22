#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>pii;
typedef vector<int> vi;
#define ST first
#define ND second

const int mod = 1000*1000*1000+7;
int cur,n,k;
int t[101];

struct Matrix {
	int m[102][102];
	Matrix operator * (Matrix &x) const {
		Matrix tmp;
		for(int i=0; i<=cur;i++) {
			for(int j=0; j<=cur;j++) {
				tmp.m[i][j] = 0;
				for(int ii=0; ii<=cur;ii++) {
					tmp.m[i][j]=((LL)tmp.m[i][j]+(LL)m[i][ii]*x.m[ii][j])%mod;
				}
			}
		}
		return tmp;
	}			
};

void Print(Matrix&x) {
	for(int i=0; i<=n;i++) {
		for(int j=0;j<=n;j++) {
			printf("%d ",x.m[i][j]);
		}
		printf("\n");
	}
	printf("-----------\n");
}

Matrix ans,nth;

void fastPow(int w) {
	while(w>0) {
		if(w&1) {
			ans=ans*nth;
		}
		nth=nth*nth;
		w/=2;
	}
}

int Pow(int a,int b) {
	int w = 1;
	while(b>0) {
		if(b&1) w = ((LL)w*a)%mod;
		a=((LL)a*a)%mod;
		b/=2;
	}
	return w;
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n;i++) {
		scanf("%d",&t[i]);
		if(!t[i]) {
			cur++;
		}
	}
	int cnt=0;
	for(int i=1; i<=cur;i++) {
		if(!t[i]) {
			cnt++;
		}
	}
	for(int i=0; i<=n;i++) {
		for(int j=0; j<=n;j++) {
			nth.m[i][j] = ans.m[i][j] = 0;
		}
	}
	for(int i=0; i<=cur;i++) {
		if(cur-i+1<=n-cur) {
			nth.m[i][i-1] = (cur-i+1)*(cur-i+1);
		}
		if(cur-i <=n-cur) {
			nth.m[i][i] = n*(n-1)/2 - (cur-i)*(cur-i) - i*(n-2*cur+i);
		}
		if(cur-i<=n-cur) {
			nth.m[i][i+1] = (i+1)*(n-2*cur+i+1);
		}
	}
	for(int i=0; i<=cur; i++) ans.m[i][i]=1;
	fastPow(k);
	int a = ans.m[cur][cnt];
	int b = 0;
	for(int i=0;i<=cur; i++) {
		b=(b+ans.m[i][cnt])%mod;
	}
	int res = ((LL)a*Pow(b,mod-2))%mod;
	//Print(ans);
	printf("%d",res);
}