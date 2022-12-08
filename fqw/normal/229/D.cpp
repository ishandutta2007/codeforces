#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXN=5010;

int f[MAXN][MAXN];
int h[MAXN], sumh[MAXN];
int n;

inline void upt(int &a, int b) {
	if(b<a) a=b;
}

int main() {
	scanf("%d", &n);
	sumh[0]=0;
	for(int i=1; i<=n; ++i) {
		scanf("%d", &h[i]);
		sumh[i]=sumh[i-1]+h[i];
	}
	memset(f, 50, sizeof(f));
	for(int i=1; i<=n; ++i)
		f[1][i]=i-1;
	for(int i=1; i<n; ++i)
		for(int j=i; j<n; ++j) {
			upt(f[i][j+1], f[i][j]+1);
			#define s(i,j) (sumh[j]-sumh[(i)-1])
			if(s(i,j)>s(j+1,n)) continue;
			int le=j+1, ri=n;
			while(le<ri) {
				int mid=(le+ri)/2;
				if(s(i,j)<=s(j+1,mid)) ri=mid;
					else le=mid+1;
			}
			int k=le;
			upt(f[j+1][k], f[i][j]+k-j-1);
		}
	int ans=1<<30;
	for(int i=1; i<=n; ++i)
		ans=min(ans, f[i][n]);
	printf("%d\n", ans);
	return 0;
}