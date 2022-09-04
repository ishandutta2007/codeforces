//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
struct cup{
	int v,i,ans;
};
bool cmp(const cup &a,const cup &b){
	return a.v<b.v;
}
bool cmp1(const cup &a,const cup &b){
	return a.i<b.i;
}
int main(){
	int n,w;
	scanf("%d %d",&n,&w);
	cup a[105];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i].v),a[i].i=i;
	sort(a,a+n,cmp); 
	int sum=0;
	for(int i=0;i<n;i++){
		a[i].ans=(a[i].v+1)/2;
		sum+=a[i].ans;
	}
	if(sum>w){
		printf("-1\n");
		return 0;
	}
	w-=sum;
	sum=w;
	for(int i=n-1;i>=0&&sum;i--){
		int k=sum;
		sum-=min(a[i].v-a[i].ans,sum);
		a[i].ans+=k-sum;
	}
	sort(a,a+n,cmp1);
	for(int i=0;i<n;i++){
		printf("%d ",a[i].ans);
	}
} 
// 10010
//1 1 2 6 3 8 4 11 5 17 6 15 7 13 8 25 9 22 10 27
//1
//2 4 6 8 10
//3 6 9
//4 2 6 8 10
//5 5 10
//6 2 3 4 6 8 10