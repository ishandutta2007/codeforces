#include <iostream>
#include <cstdio>

#define mid ( (l + r) >> 1 )
#define ls l,mid,t<<1
#define rs mid+1,r,t<<1^1 

#define N 200005

using namespace std;

struct Node{ int F[5][5]; }tr[4*N],id,ans;
int a[N],ll,rr,n,q;
char s[N];
inline void ut(int &x,int y) { x = min(x,y); }
Node operator +(Node p1,Node p2) {
	Node tmp = id;
	for (int i=0;i<=4;i++)
		for (int j=i;j<=4;j++)
			for (int k=i;k<=j;k++)
				ut( tmp.F[i][j] , p1.F[i][k] + p2.F[k][j] );
	return tmp;
}

Node color(int x) {
	Node tmp = id;
	for (int i=0;i<=4;i++) tmp.F[i][i] = 0;
	if (a[x] == 2) tmp.F[0][0] = 1 , tmp.F[0][1] = 0;
	if (a[x] == 0) tmp.F[1][1] = 1 , tmp.F[1][2] = 0; 
	if (a[x] == 1) tmp.F[2][2] = 1 , tmp.F[2][3] = 0;
	if (a[x] == 7) tmp.F[3][3] = 1 , tmp.F[3][4] = 0;
	if (a[x] == 6) tmp.F[3][3] = tmp.F[4][4] = 1;
	return tmp;
}

Node build(int l,int r,int t) {
	return l == r ? tr[t] = color(l) : tr[t] = build(ls) + build(rs);
}
void query(int l,int r,int t) {
	if (l > rr || r < ll) return ;
	if (l >= ll && r <= rr) { ans = ans + tr[t]; return ; }
	query(ls); query(rs);
}

int main() {
	
	for (int i=0;i<=4;i++)
		for (int j=0;j<=4;j++) id.F[i][j] = 2147483647 >> 1;
	
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) a[i] = s[i] - '0';
	
	build(1,n,1);
	while (q--) {
		scanf("%d%d",&ll,&rr); ans = id; for (int i=0;i<=4;i++) ans.F[i][i] = 0;
		query(1,n,1); 
		if (ans.F[0][4] > n) puts("-1"); else printf("%d\n",ans.F[0][4]);
	}
	return 0;
}