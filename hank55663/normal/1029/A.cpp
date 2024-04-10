#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
#define N
int f[55];
void KMP(char *c){
	int j=-1;
	f[0]=-1;
	for(int i=1;c[i]!=0;i++){
		while(j!=-1&&c[i]!=c[j+1])j=f[j];
		if(c[i]==c[j+1])j++;
		f[i]=j;
	}
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	char c[55];
	scanf("%s",c);
	KMP(c);
	printf("%s",c);
	//printf("%d\n",f[n-1]);
	for(int i=1;i<k;i++){
		printf("%s",c+f[n-1]+1);
	}
}
/*
   s       20006
 qqqqqq  0~10000
bbbbbbbb  10001 20000
  5 5 5    20001 20005
     t    20007





*/