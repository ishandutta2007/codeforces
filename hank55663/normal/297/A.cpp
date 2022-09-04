#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
int main(){
	char a[1005],b[1005];
	scanf("%s %s",a,b);
	int sum=0;
	for(int i=0;a[i]!=0;i++)
	if(a[i]=='1')
	sum++;
	if(sum%2)
	sum++;
	for(int i=0;b[i]!=0;i++){
		if(b[i]=='1')
		sum--;
	}
	if(sum>=0)
	printf("YES\n");
	else
	printf("NO\n");
}