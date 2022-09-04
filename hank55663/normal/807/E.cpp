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
#define N 200005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
LL save [100005];
LL aa[100005];
int hihi[100005];
int main() {
	int n;
	scanf("%d",&n);
	MEM(aa);
	MEM(aa);
	int x=0,y=0,sum=1;
	LL a;
	scanf("%I64d",&a);
	if(a!=1)
	{
		printf("-1\n");
		return 0;
	}
	hihi[y]=1;
	aa[y++]=1;
	for(int i=1;i<n;i++){
		scanf("%I64d",&a);
		if(a==1)
		hihi[y]=1,aa[y++]=1,sum=y;
		else if(a==aa[y]*2)
		hihi[y]++,aa[y++]=a;
		else if(y!=0&&a==aa[y-1]*2)
		hihi[0]++,aa[0]=a,y=1;
		else{
			save[x++]=a;
	//		printf("%d\n",a);
		//	printf("%d %d %d %d\n",x,a,y);
			//printf("%d %d %d %d\n",i,x,a,sum);
		}
	}
//	printf("%d %d",x,sum);
	if(x>sum){
		printf("-1\n");
		return 0;
	} 
	int Min,Max=sum+1;
	int add=x;
//	printf("%d %d",x,sum);
	for(int i=sum-1;i>=0&&add<=i+1;i--)add+=hihi[i],Min=i;
//	printf("%d %d\n",Min,Max);
	LL v[100005];
	while(Min<Max-1){
		MEM(v);
		int xx=0;
		for(xx=0;xx<x;xx++)
		v[xx]=save[xx];
		int mid=(Max+Min)/2;
		for(int i=mid;i<sum;i++){
			for(LL j=1;j<=aa[i];j*=2)
			v[xx++]=j,assert(xx<100000);;
		} 
		sort(v,v+xx);
		reverse(v,v+xx);
		int ok=1;
		for(int i=0;i<xx;i++){
		//	printf("%d %d %d %d\n",v[i],aa[i]*2,mid,i);
			if(v[i]>aa[i]*2)
			ok=0;
		}
		if(ok){
			Max=mid;
		} 
		else{
			Min=mid;
		}
	}
//	printf("%d %d\n",Min,sum);
	if(Min==sum){
		printf("-1\n");
	}
	else {
		printf("%d",Min+1);
		for(int i=Min+2;i<=sum;i++)printf(" %d",i); 
	}
}