#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

int n;
#define Maxn 2005
int a[Maxn],d[Maxn];

int cnt[2];

void ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	rep(i,1,n)scanf("%d",&d[i]);
}

pii edge[Maxn];int ed=0;

int main(){
	scanf("%d",&n);
	ask(1);
	rep(i,1,n){
		a[i]=d[i];
		if(a[i]>0)cnt[a[i]&1]++;
	}
	int t=0;
	if(cnt[1]<cnt[0])t=1;
	rep(i,1,n)
		if(a[i]%2==t){
			if(i!=1)ask(i);
			else rep(j,1,n)d[j]=a[j];
			rep(j,1,n)
				if(d[j]==1)edge[++ed]=pii(i,j);
		}
	printf("!\n");
	rep(i,1,n-1)printf("%d %d\n",edge[i].FR,edge[i].SE);
	fflush(stdout);
	return 0;
}