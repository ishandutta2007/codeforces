#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
#define N 300050
typedef long long ll;
int n;
int a[N];
void update(int l,int r,int x,int y,int p) {
	if(x<=l&&y>=r) {
		return ;
	}
	int mid=(l+r)>>1;
}
void pushup(int p) {
	p=p;
}
int main() {
	scanf("%d",&n);
	int siz=(int)sqrt(n);
	int i;
	// for(i=0;i<n/3;i++) {
	// 	printf("%d %d %d ",i*3+3,i*3+2,i*3+1);
	// }
	// while(n%3!=0) printf("%d ",n--);
	for(i=1;i<=n;) {
		int x=siz;

		int pop=i;
		for(;x--;i++) {
			a[i]=x+pop;
		}
		if(i+siz>n) break;
	}

	int j;
	for(j=0;i<=n;i++,j++) {
		a[i]=n-j;
	}
	for(i=1;i<=n;i++) printf("%d ",a[i]);
}