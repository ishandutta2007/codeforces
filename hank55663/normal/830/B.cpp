#include<stdio.h>
#include<map>
#include<set>
#include<queue>
#include<vector> 
#include<string>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
#define seg pair<pii,pii>
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define rank Rank
using namespace std;
typedef long long LL;
int s[1<<20];
void add(int index,int n){
	if(index==0)
	return;
	for(int i=index;i<(1<<20);i+=i&-i)
	s[i]+=n;
}
LL search(int index){
	LL res=0;
	for(int i=index;i>0;i-=i&-i)
	res+=s[i];
	return res;
} 
LL ask(int l,int r,int n){
	if(l<r)
	return search(r)-search(l);
	else
	return search(n)-search(l)+search(r);
}
int main()
{
	int n;
	scanf("%d",&n);
	pii a[100005];
	for(int i=1;i<=n;i++){
		int b;
		scanf("%d",&b);
		a[i]=mp(b,i);
		add(i,1);
	}
	sort(a+1,a+n+1);
	int ini=0;
	queue<int> q;
	q.push(a[1].y);
	LL ans=0;
	for(int i=2;i<=n;i++){
	//	printf("%d %d\n",a[i].x,a[i].y);
		if(a[i].x==a[i-1].x)
		q.push(a[i].y);
		else{
		//	printf("%d",i);
			int xx=q.front();
			while(q.front()<ini){
				q.push(q.front()),q.pop();
				if(xx==q.front())
				break;
			}
		//	printf("%d",i);
			while(!q.empty()){
			//	printf("%d",i);
				ans+=ask(ini,q.front(),n);
			//	printf("%d",i);
				ini=q.front();
			//	printf("%d\n",ini);
			//	printf("%d",i);
				add(ini,-1);
				q.pop();
			}
		//	printf("%d\n",ans);
			q.push(a[i].y);
		}
	}
	int xx=q.front();
			while(q.front()<ini){
				q.push(q.front()),q.pop();
				if(xx==q.front())
				break;
			}
	while(!q.empty()){
		//	printf("%d",i);
			ans+=ask(ini,q.front(),n);
		//	printf("%d",i);
			ini=q.front();
	//		printf("%d\n",ini);
		//	printf("%d",i);
			add(ini,-1);
			q.pop();
	}
	printf("%I64d\n",ans);
}
/* 4 9 6 3 7 8 8 2 9 1
/* 0 7 1 7 7*/