#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n,s;
	scanf("%d %d",&n,&s);
	int a[100005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int Max=n+1,Min=0;
	LL temp[100005];
	LL aa=0;
	while(Max>Min+1){
		int mid=(Max+Min)/2;
		for(int i=0;i<n;i++)
		temp[i]=a[i]+(LL)(i+1)*mid;
		sort(temp,temp+n);
		LL sum=0;
		for(int i=0;i<mid;i++)
		sum+=temp[i];
		if(sum>s)
		Max=mid;
		else
		Min=mid,aa=sum;
	} 
	printf("%d %I64d\n",Min,aa);
}