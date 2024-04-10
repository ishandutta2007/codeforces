#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
	pii p[400005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		p[i*2]=mp(a,0);
		p[i*2+1]=mp(b,1);
	}
	sort(p,p+2*n);
	int sum=0;
	for(int i=0;i<2*n;i++){
		if(p[i].y==0){
			sum++;
		}
		else{
			sum--;
		}
		if(sum>2){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}
/*
14%20,15#17
20,14-18
1#5,11,4%10,14-18,20,21
11,21,20,14-18,4%10,1#5

*/