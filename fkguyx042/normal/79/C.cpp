#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#define N 100010
#define M 1000010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
	int l,r;
} a[M];
int i,j,k,n,m,t,an,re;
char p[N],s[N];
map<int,int> Map;
set<int> Set;
inline bool cc1(const ww &a,const ww &b) {
	return a.l<b.l;
}
int main() {
	scanf("%s",p+1);
	n=strlen(p+1);
	scanf("%d",&m);
	For(i,1,m) {
		scanf("%s",s+1);
		int len=strlen(s+1);
		For(j,len,n) {
			int F=0;
			For(k,1,len) if (s[k]!=p[j-len+k]) F=1;
			if (!F) a[++t]=(ww){j-len+1,j};
		}
	}
	sort(a+1,a+t+1,cc1);
	Set.insert(n+1);
	For(i,1,t) Map[a[i].r]++,Set.insert(a[i].r);
	j=1; re=1;
	For(i,1,n) {
		int r=*Set.begin();
		r--;
		int len=r-i+1;
		if (len>an) an=len,re=i;
		for (;j<=t&&a[j].l==i;j++) {
			int A=a[j].r;
			if (!(--Map[A])) Set.erase(A);
		}
	}
	printf("%d %d\n",an,re-1);
	return 0;
}