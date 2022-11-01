#include <bits/stdc++.h>
#define N 1000500
using namespace std;
inline int rd() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int F[N][2],a[N],n;
inline void ut(int &x,int y) {x = max(x,y);}

int main() {
	n = rd();
	for (int i=1;i<=n;i++) a[i] = rd();
	F[0][0] = 0, F[0][1] = -1000000000;
	for (int i=1;i<=n;i++) {
		F[i][0] = F[i-1][0], F[i][1] = F[i-1][1];
		if (a[i]&1) {
			ut( F[i][0], F[i-1][1] + a[i] );
			ut( F[i][1], F[i-1][0] + a[i] );
		} else {
			ut( F[i][0], F[i-1][0] + a[i] );
			ut( F[i][1], F[i-1][1] + a[i] );
		}
	}
	printf("%d\n",F[n][1]);
	return 0;
}