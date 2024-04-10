//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a [100005];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	LL ans=0;
	int mi=1e9;
	for(int i=0;i<n;i++)
	mi=min(a[i],mi);
	for(int i=0;i<n;i++){
		if((a[i]-mi)%k!=0){
			printf("-1\n");
			return 0;
		}
		else
		ans+=(a[i]-mi)/k;
	}
	printf("%I64d\n",ans);
}

/*90 110
180 220
270 330
360 440
450 550
540 660
630 770
xy=k(x+y)
xy=kx+ky
kx/(x-k)=y 
*/