#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 5000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
int n,m,x,y,q,sw[20],a[N][N],b[N];char st[20];
struct pr{int x,id;}w[N];
bool cmp(pr x,pr y){return x.x<y.x;}
using namespace std;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,0,n-1)scanf("%d",&sw[i]);
	rep(i,0,(1<<n)-1){w[i].id=i;
		rep(j,0,n-1)if(!((i>>j)&1))w[i].x+=sw[j];
	}
	sort(w,w+(1<<n),cmp);w[1<<n].x=inf;
	rep(i,1,m){
		scanf("%s",st);x=0;
		rep(j,0,n-1)if(st[j]=='1')x+=1<<j;b[x]++;
	}
	rep(i,0,(1<<n)-1)a[i][0]=b[w[0].id^i];
	rep(i,0,(1<<n)-1)rep(j,1,(1<<n)-1)a[i][j]=a[i][j-1]+b[w[j].id^i];
	rep(i,1,q){
		scanf("%s",st);scanf("%d",&y);x=0;
		rep(j,0,n-1)if(st[j]=='1')x+=1<<j;
		printf("%d\n",a[x][upper_bound(w,w+(1<<n)+1,(pr){y,0},cmp)-w-1]);
	}
}