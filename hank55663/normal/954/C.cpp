#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int a[200005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int y=1;
	for(int i=1;i<n;i++){
		if(abs(a[i]-a[i-1])!=1){
			if(a[i]==a[i-1]){
				printf("NO\n");
				return 0;
			}
			if(y!=1&&y!=abs(a[i]-a[i-1]))
			{
				printf("NO\n");
				return 0;
			}
			else
			y=abs(a[i]-a[i-1]);
		}
	}
	if(y!=1)
	for(int i=1;i<n;i++){
		if(abs(a[i]-a[i-1])==1){
			if((a[i]-1)/y!=(a[i-1]-1)/y)
			{
				//printf("%d",i);
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n1000000000 %d\n",y);
}
/*
BC
ACC
AABC
CC
ABC
AACC*/