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
	char c[1005];
	scanf("%s",c);
	int ans=1;
	for(int i=0;c[2*i+1]!=0;i++){
		int ok=1;
		for(int j=i+1;j<=2*i+1;j++){
			if(c[j-i-1]!=c[j]){
				ok=0;
				break;
			}
		}
		if(ok)
		ans=i+1;
	}
	printf("%d\n",n-ans+1);
}
/*
BC
ACC
AABC
CC
ABC
AACC*/