#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
	int n,w;
	scanf("%d %d",&n,&w);
	int now=0,Min=0,Max=0;
	for(int i =1;i<=n;i++){
		int x;
		scanf("%d",&x);
		now+=x;
		Min=min(now,Min);
		Max=max(now,Max);
	}
	//-Min,w-Max
//	printf("%d %d\n",Min,Max);
	printf("%d\n",max(w-(Max-Min)+1,0));
}