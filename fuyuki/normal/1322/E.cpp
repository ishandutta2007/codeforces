#include<bits/stdc++.h>
using namespace std;
#define N_ 501000
#define pii pair<int,int>
using namespace std;
int n;
int w[N_], Mn[20][N_], Mx[20][N_], MM[N_], Res[N_], Ans;
pii Get(int b, int e) {
	int t = MM[e - b];
	return { min(Mn[t][b],Mn[t][e - (1 << t)]), max(Mx[t][b],Mx[t][e - (1 << t)]) };
}
int main() {
//	freopen("test.in","r",stdin);
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for(i=1; i<N_; i++) {
		MM[i] = MM[i - 1];
		while ((1 << MM[i] + 1) <= i)MM[i]++;
	}
	w[0] = w[1], w[n + 1] = w[n];
	for (i = 0; i <= n; i++) {
		Mn[0][i] = max(w[i], w[i + 1]);
		Mx[0][i] = min(w[i], w[i + 1]);
	}
	for (i = 0; i < 19; i++) {
		for (j = 0; j <= n-(1<<i); j++) {
			Mn[i + 1][j] = min(Mn[i][j], Mn[i][j + (1 << i)]);
			Mx[i + 1][j] = max(Mx[i][j], Mx[i][j + (1 << i)]);
		}
	}
	for (i = 1; i <= n; i++) {
		int b = 1, e = min(i, n + 1 - i), mid, r = 0;
		while (b <= e) {
			mid = (b + e) >> 1;
			pii t = Get(i - mid, i + mid);
			if (t.first <= t.second) {
				r = mid;
				e = mid - 1;
			} else b = mid + 1;
		}
//		cout<<r<<'\n';
//		if (r == 1)Res[i] = w[i];
//		else
			pii t = Get(i - r, i + r);
			if (w[i] > w[i - 1]) {
				if (r % 2 == 0) Res[i] = t.second;
				else Res[i] = t.first;
			} else {
				if (r % 2 == 1) Res[i] = t.second;
				else Res[i] = t.first;
			}
		Ans = max(Ans, r - 1);
	}
	printf("%d\n", Ans);
	for (i = 1; i <= n; i++)printf("%d ", Res[i]);
}
/*
#include<bits/stdc++.h>
using namespace std;
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=5e5+5;
int n,p,a[N],b[N],lg[N],s[20][N],t[20][N];
V input(){
	scanf("%d",&n),lg[0]=-1;
	FOR(i,1,n)scanf("%d",a+i),lg[i]=lg[i>>1]+1;
}
V init(){
	a[0]=a[1],a[n+1]=a[n];
	FOR(i,0,n)s[0][i]=max(a[i],a[i+1]),t[0][i]=min(a[i],a[i+1]);
	FOR(i,0,18)FOR(j,0,n-(1<<i))s[i+1][j]=min(s[i][j],s[i][j+(1<<i)]);
	FOR(i,0,18)FOR(j,0,n-(1<<i))t[i+1][j]=max(t[i][j],t[i][j+(1<<i)]);
}
V ask(int l,int r,int&x,int&y){
	r-=1<<(p=lg[r-l]),x=min(s[p][l],s[p][r]),y=max(t[p][l],t[p][r]);
}
V work(){
	FOR(i,1,n){
		int l=1,r=min(i,n-i+1),mid,x,y;
		while(mid=l+r>>1,l^r){
			ask(i-mid,i+mid,x,y);
			if(x<=y)r=mid;
			else l=mid+1;
		}
		cout<<mid<<'\n';
		ask(i-mid,i+mid,x,y);
		b[i]=x;
	}
	FOR(i,1,n)cout<<b[i]<<' ';
}
int main(){
	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}
*/