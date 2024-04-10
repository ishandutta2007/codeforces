#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int main(){
	LL k;
	int a,b;
	scanf("%I64d %d %d",&k,&a,&b);
	map<pii,pair<pii,int> >m;
	int A[4][4];
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++)
			scanf("%d",&A[i][j]);
	int B[4][4];
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++)
			scanf("%d",&B[i][j]);
	LL aa=0,bb=0,now=0;
	while(k!=0&&m.find(mp(a,b))==m.end()){
		m[mp(a,b)]=mp(mp(aa,bb),now);
		if(a==1){
			if(b==2)
			bb++;
			if(b==3)
			aa++;
		} 
		if(a==2){
			if(b==1)
			aa++;
			if(b==3)
			bb++;
		} 
		if(a==3){
			if(b==1)
			bb++;
			if(b==2)
			aa++;
		}
		now++;
		k--;
		int tempa=A[a][b];
		int tempb=B[a][b];
		a=tempa;
		b=tempb;
	//	printf("%d %d\n",a,b);
	}
	now-=m[mp(a,b)].y;
	LL adda=aa-m[mp(a,b)].x.x;
	LL addb=bb-m[mp(a,b)].x.y;
	aa+=k/now*adda;
	bb+=k/now*addb;
	k%=now;
	while(k){
			if(a==1){
			if(b==2)
			bb++;
			if(b==3)
			aa++;
		} 
		if(a==2){
			if(b==1)
			aa++;
			if(b==3)
			bb++;
		} 
		if(a==3){
			if(b==1)
			bb++;
			if(b==2)
			aa++;
		}
		k--;
		int tempa=A[a][b];
		int tempb=B[a][b];
		a=tempa;
		b=tempb;
	}
	printf("%I64d %I64d\n",aa,bb);
}
/*3 2 6 5 4 1
1 3 2 6 5 4*/