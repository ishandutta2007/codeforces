#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 2000005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
const LL mod =1e9+7;
int main(){
	LL n,m;
	scanf("%I64d %I64d",&n,&m);
	LL Min=m,Max=min(n,2000000000ll+7+m);
	while(Max>Min+1){
		LL mid=(Max+Min)/2;
		if(	(1+mid-m-1)*(mid-m-1)/2+mid>=n)
		Max=mid;
		else
		Min=mid;
	}
	printf("%I64d\n",Max);
	
}
//6 10 14   (6+(n-2)*4)*(n-1)/2; 
/*
 29786
   850
   850
 31486*/