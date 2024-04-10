#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define N 1000005
#define x first 
#define y second
typedef long long LL;
using namespace std;
int main(){
	int n;
	int a[100005];
	int b[100005];
	pii aa[100005];
	LL suma=0,sumb=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		aa[i].x=a[i];
		aa[i].y=i+1;
		suma+=a[i];
	}
	for(int i=1;i<=n;i++)
	scanf("%d",&b[i]),sumb+=b[i];
	printf("%d\n",(n/2)+1);
	sort(aa,aa+n);
	reverse(aa,aa+n);
	LL totb=0;
	for(int i=0;i<n;i+=2)
	totb+=b[aa[i].y];
	if(n%2==0)
	totb+=b[aa[1].y];
	if(totb*2>sumb){
		for(int i=0;i<n;i+=2)
		printf("%d ",aa[i].y);
		if(n%2==0)
		printf("%d",aa[1].y);
	}
	else{
		printf("%d",aa[0].y);
		for(int i=1;i<n;i+=2)
		printf(" %d",aa[i].y);
	}
}