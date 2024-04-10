#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include <iomanip>
#include<assert.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
int main(){
	LL n, r,l;
	scanf("%I64d %I64d %I64d",&n,&l,&r); 
	int a[100];
	memset(a,0,sizeof(a));
	for(int i=0;;i++){
		if(!n){
			n=i;
			break;
		}
		a[i]=n&1;
		n>>=1;
	} 
	int ans=0;
	for(LL i=l;i<=r;i++){
		LL b=i;
		for(int j=0;;j++){
			if(b&1){
			ans+=a[n-j-1];
			//printf("%d %d %d\n",n,i,j);
			break;
			}
			b>>=1;
		}
	}
	printf("%d\n",ans);
}