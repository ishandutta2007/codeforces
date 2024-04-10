// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int maxn=(2e5)+10;
const double eps=1e-6;
int n,K;
double ans=1e18;
struct node {
	int x,y,id;
} d[maxn];
ll sqr(ll x) { return x*x; }
double dis(node A,node B) { return sqrt(sqr(A.x-B.x)*1.0+sqr(A.y-B.y)*1.0); }
bool cmp(node A,node B) { return (A.x==B.x?A.y<B.y:A.x<B.x); }
int tot,p[10]; double t[1000],rem[10][10];
double Get(node A,node B) { return (A.x==B.x?1e9:(A.y-B.y)*1.0/(A.x-B.x)); }
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(K);
	for (int i=1;i<=n;i++) read(d[i].x),read(d[i].y);
	if (n<=3) {
		p[1]=K; tot=1;
		for (int i=1;i<=n;i++) if (i!=K) p[++tot]=i;
		do {
			double tmp=0;
			for (int i=1;i<n;i++) tmp+=dis(d[p[i]],d[p[i+1]]);
			ans=min(ans,tmp);
		} while (next_permutation(p+2,p+n+1));
		printf("%.10lf\n",ans);
		return 0;
	}
	for (int i=1;i<=n;i++) d[i].id=i;
	random_shuffle(d+1,d+n+1);
	for (int i=1;i<=4;i++) for (int j=i+1;j<=4;j++) {
		t[++tot]=rem[i][j]=Get(d[i],d[j]);
	//	printf("%.5lf\n",t[tot]);
	}
	sort(t+1,t+tot+1);
	int L=1,R=-1,pos,mx=0;
	for (int i=1;i<=tot+1;i++) {
		if (i>tot||fabs(t[i]-t[i-1])>eps) {
			if (L!=-1&&R!=-1) {
				if (R-L+1>mx) mx=R-L+1,pos=L;
			}
			//printf("%d %d\n",L,R);
			L=R=i+1;
		} else R=max(R,i);
	}
	int fd=-1;
	for (int i=1;i<=4&&fd==-1;i++) for (int j=i+1;j<=4&&fd==-1;j++) {
		if (fabs(rem[i][j]-t[pos])<eps) { fd=i; break; }
	}
	for (int i=2;i<=n;i++) if (fabs(Get(d[fd],d[i])-t[pos])>eps) { fd=i; break; }
	//printf("fd=%d %.5lf\n",fd,t[pos]);
	swap(d[fd],d[n]);
	sort(d+1,d+n,cmp);
	for (int i=1;i<=n;i++) if (d[i].id==K) { K=i; break; }
	if (K==n) {
		ans=dis(d[1],d[n-1])+min(dis(d[n],d[n-1]),dis(d[n],d[1]));
	} else {
		for (int i=K;i<n;i++) {
			ans=min(ans,dis(d[K],d[i])+dis(d[i],d[1])+dis(d[1],d[n])+(i!=n-1?dis(d[n],d[i+1])+dis(d[i+1],d[n-1]):0));
			ans=min(ans,dis(d[K],d[1])+dis(d[1],d[i])+dis(d[i],d[n])+(i!=n-1?dis(d[n],d[i+1])+dis(d[i+1],d[n-1]):0));
		}
		reverse(d+1,d+n);
		K=n-K;
		for (int i=K;i<n;i++) {
			ans=min(ans,dis(d[K],d[i])+dis(d[i],d[1])+dis(d[1],d[n])+(i!=n-1?dis(d[n],d[i+1])+dis(d[i+1],d[n-1]):0));
			ans=min(ans,dis(d[K],d[1])+dis(d[1],d[i])+dis(d[i],d[n])+(i!=n-1?dis(d[n],d[i+1])+dis(d[i+1],d[n-1]):0));
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/