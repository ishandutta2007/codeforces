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
	int k,q;
	scanf("%d %d",&k,&q);
	double qq[1005];
	for(int i=0;i<1005;i++)
	qq[i]=0;
	qq[0]=1;
	int ans[1005],l=1;
	for(int i=1;;i++)
	{
		for(int j=k;j>0;j--)
		qq[j]=qq[j-1]*(k-j+1)/k+qq[j]*j/k;
		qq[0]=0;
		while(qq[k]>(l-1e-7)/2000.0&&l<=1000)
		ans[l]=i,l++;
		//system("PAUSE");
		if(l>1000)
		break;
	}
	while(q--){
		int qqq;
		scanf("%d",&qqq);
		printf("%d\n",ans[qqq]);
	}
}