#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define index Index
#define N 300005
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int a[200005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	char c[200005];
	scanf("%s",c);
	c[n-1]='0';
	int last=0;
	for(int i=0;i<n;i++){
		if(c[i]=='0'){
			sort(a+last,a+i+1);
			last=i+1;
		}
	}
	for(int i=0;i<n;i++){
	//	printf("%d ",a[i]);
		if(a[i]!=i+1){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}