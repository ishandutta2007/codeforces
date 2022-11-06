#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18;
int n;
//int P,a[N],b[N];
int ad(int x,int y){return (x+n+y-1)%n+1;}
int q(int x){int y;
	printf("? %d\n",x);fflush(stdout);
	/*rep(i,1,n)if(i==P)b[ad(i,1)]+=a[i];
	else b[ad(i,-1)]+=a[i]/2,b[ad(i,1)]+=a[i]-a[i]/2;
	rep(i,1,n)a[i]=b[i],b[i]=0;*/
	scanf("%d",&y);
	printf("? %d\n",x);fflush(stdout);
	/*rep(i,1,n)if(i==P)b[ad(i,1)]+=a[i];
	else b[ad(i,-1)]+=a[i]/2,b[ad(i,1)]+=a[i]-a[i]/2;
	rep(i,1,n)a[i]=b[i],b[i]=0;
	return a[x];*/
	scanf("%d",&y);
	return y;
}

void ck(int p){
	int x=q(p);
	if(x>q(ad(p,-1))&&x<q(ad(p,1))){
		printf("! %d\n",p);fflush(stdout);exit(0);
	}
}

int main(){srand(time(0));
	int k;scanf("%d%d",&n,&k);
	//scanf("%d",&P);rep(i,1,n)a[i]=k;
	int p=rand()*rand()%n+1,x=q(p);
	while(x==k)p=rand()*rand()%n+1,x=q(p);
	if(x<k)p=ad(p,-n/2);
	int d=(n-1)/2;
	while(d>1){
		ck(p);int md=d/2;
		if(q(p)<=q(ad(p,-md))){
			p=ad(p,-md);d-=md;
		}else d=md;
	}
	ck(p);ck(ad(p,-1));ck(ad(p,1));
}