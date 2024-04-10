#include<stdio.h>
#include<time.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
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
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
#define assert Assert
using namespace std;
typedef long long LL;
using namespace std;
void assert(bool a){
	if(!a){	
	int b=1;
		while(1){
			b=b*b%10000007;
		}
	}
}
int main(){
	int n,start,x;
	int visit[50005];
	scanf("%d %d %d",&n,&start,&x);
	if(n<1999){
		int ans=1e9+8;
		for(int i=1;i<=n;i++){
			printf("? %d\n",i);
			fflush(stdout);
			int a,b;
			scanf("%d %d",&a,&b);
			if(a>=x)
			ans=min(a,ans);
		} 
	//	assert(ans>=x);
		if(ans==1e9+8){
			ans=-1;
		}
		printf("! %d\n",ans);
		fflush(stdout);
		return 0; 
	}
	else{
		int cnt=1;
		printf("? %d\n",start);
		fflush(stdout);
		int a,b;
		scanf("%d %d",&a,&b);
		if(a>=x){
			printf("! %d\n",a);
			fflush(stdout);
			return 0;
		}
		visit[start]=1;
		visit[b]=1;
		srand(7123);
		vector<int> v;
		MEM(visit);
		pii Min=mp(a,b);
		for(int i=0;i<1000;i++){
			int hi=((rand()<<10+rand())%n+n)%n+1;
			while(visit[hi]){
				hi=rand()%n+1; 
			}
			visit[hi]=1;
			printf("? %d\n",hi);
			cnt++;
			fflush(stdout);
			scanf("%d %d",&a,&b);
			visit[b]=1;
			if(a<x)
			Min=max(mp(a,b),Min); 
		}
		b=Min.y;
		while(b!=-1){
			printf("? %d\n",b);
			cnt++;
			fflush(stdout);
			scanf("%d %d",&a,&b);
			assert(a!=-1||b!=-1);
			if(a>=x){
				printf("! %d\n",a);
				fflush(stdout);
				return 0;
			}
		}
		printf("! -1\n");
		fflush(stdout);
	}
}
/*
14%20,15#17
20,14-18
1#5,11,4%10,14-18,20,21
11,21,20,14-18,4%10,1#5

*/