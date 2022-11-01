#include <iostream>
#include <cstdio>
#include <cstring>

#define mid ((l+r) >> 1)
#define ls l,mid,t<<1
#define rs mid+1,r,t<<1^1

#define N 200050

using namespace std;
char a[N],b[N];
int n,m,tr[4*N];
int x,v,ll,rr,tmp,mx,ansl,ansr;
void update(int l,int r,int t) {
	if (l > x || r < x) return ;
	if (l == r) { tr[t] = v; return ; }
	update(ls); update(rs);
	tr[t] = max( tr[t<<1] , tr[t<<1^1] );
}

void query(int l,int r,int t) {
	if (l > rr || r < ll) return ;
	if (l >= ll && r <= rr) {
		tmp = max(tr[t] , tmp);
		return ;
	}
	query(ls); query(rs);
}

int main() {
	scanf("%s",a+1); n = strlen(a+1);
	scanf("%s",b+1); m = strlen(b+1);
	
	int p1,p2;
	p1 = 1 , p2 = 1;
	while (p1 <= n && p2 <= m) {
		if (a[p1] == b[p2]) {
			x = p1 , v = p2 , update(1,n,1);
			if (p2 > mx) {
				mx = p2;
				ansl = p2 , ansr = m+1;
			}
			p1++ , p2++;
			
		}
		else
			p1++;
	}
	
	p1 = n , p2 = m;
	while (p1 >= 1 && p2 >= 1) {
		if (a[p1] == b[p2]) {
			tmp = 0;
			ll = 1 , rr = p1-1 , query(1,n,1);
			if (tmp < p2 && mx < tmp + (m-p2+1) ) {
				mx = tmp + (m-p2+1);
				ansl = tmp , ansr = p2;
			}
			p1-- , p2--;
		}
		else
			p1--;
	}
	
	if (mx == 0) { puts("-"); return 0; }
	for (int i=1;i<=ansl;i++) printf("%c",b[i]);
	for (int i=ansr;i<=m;i++) printf("%c",b[i]);
	printf("\n");
	return 0;
}