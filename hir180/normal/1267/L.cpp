#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rec(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
typedef pair<int,int> P;
typedef long long ll;
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define INF 1000000000
int n,l,k;
char a[1000005];
int pre[1000005];
char ans[1005][1005];
int cur;
void recc(int lb,int len){
	//[lb,k-1]
	if(len == l) return;
	for(int x=lb;x<k;x++) ans[x][len] = a[cur++];
	int a = pre[cur-1];
	a += k-cur;
	a = max(a,lb);
	recc(a,len+1);
}
int main(){
	scanf("%d%d%d",&n,&l,&k);
	scanf("%s",&a);
	sort(a,a+(n*l));
	rep(i,n*l){
		if(i == 0) pre[i] = 0;
		else if(a[i-1] != a[i]) pre[i] = i;
		else pre[i] = pre[i-1];
	}
	rec(i,n) rep(j,l) ans[i][j] = 'A';
	recc(0,0);
	rec(i,n) rep(j,l) if(ans[i][j] == 'A') ans[i][j] = a[cur++];
	assert(cur == n*l);
	rep(i,n) printf("%s\n",ans[i]);
}