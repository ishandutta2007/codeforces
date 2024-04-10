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
int n,b[1010],c[1010];
set<int> A[2];
map<int,vector<int> > M;
int vis[1010];
void dfs(int x,int all,vector<int> &now,int sum) {
	if (all>n-x+1) return;
	if (all==0) {
		if (M.count(sum)) {
			puts("YES");
			vector<int> &now2=M[sum];
			for (int i : now) vis[i]=1;
			for (int i : now2) if (vis[i]) vis[i]=0; else vis[i]=2;
			int k=0;
			for (int i=0;i<now.size();i++) {
				printf("%d ",k);
				k=b[now[i]]-k;
				printf("%d ",k);
				k=b[now2[i]]-k;
			}
			for (int i=1;i<=n;i++) if (!vis[i]) printf("%d ",b[i]);
			puts("");
			exit(0);
		}
		M[sum]=now; return;
	}
	dfs(x+1,all,now,sum);
	now.push_back(x);
	dfs(x+1,all-1,now,sum+b[x]);
	now.pop_back();
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(b[i]);
	sort(b+1,b+n+1);
	int N=unique(b+1,b+n+1)-b-1;
	if (N<n) {
		puts("YES");
		for (int i=1;i<=N;i++) printf("%d ",b[i]);
		for (int i=N+1;i<=n;i++) printf("0 ");
		puts("");
		return 0;
	}
	for (int i=1;i<=n;i++) c[i]=(abs(b[i])%2),A[c[i]].insert(i);
	if (n==2) {
		if (b[1]==b[2]) printf("YES\n%d %d\n",0,b[1]);
		else puts("NO");
	} else {
		for (int xx=0;xx<=1;xx++) for (int yy=xx;yy<=1;yy++) {
			if ((int)A[xx].size()&&(int)A[yy].size()) {
				int x=*A[xx].begin();
				A[xx].erase(x);
				if ((int)A[yy].size()>0) {
					int y=*A[yy].begin(); A[yy].erase(y);
					if ((int)A[(xx+yy)%2].size()>0) {
						int z=*A[(xx+yy)%2].begin();
						puts("YES");
						int tmp=(b[z]-b[x]-b[y])/2; tmp*=-1;
						printf("%d ",tmp);
						for (int i=1;i<=n;i++) if (i!=z) printf("%d ",b[i]-tmp); puts("");
						return 0;
					}
					A[yy].insert(y);
				}
				A[xx].insert(x);
			}
		}
		if (n==3) { puts("NO"); return 0; }
		for (int i=1;i<=n/2;i++) {
			vector<int> now;
			M.clear();
			dfs(1,i,now,0);
		}
		puts("NO");
	}
	
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