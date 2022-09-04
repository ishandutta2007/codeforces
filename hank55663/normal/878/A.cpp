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
#define pi 3.14159265359
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
int main(){
	int a[20];
	a[10]=0;
	for(int i=0;i<10;i++)
	a[i]=1<<i;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char c[2];
		int x;
		scanf("%s %d",c,&x);
		for(int j=0;j<=10;j++){
			if(c[0]=='|')
			a[j]|=x;
			if(c[0]=='^')
			a[j]^=x;
			if(c[0]=='&')
			a[j]&=x;
		}
	}
	int an=(1<<10)-1,o=0,xo=0;
	for(int i=0;i<10;i++){
		if(a[i]&(1<<i)){
			if(a[10]&(1<<i)){
				o|=(1<<i);
			}
		}
		else{
			if(a[10]&(1<<i)){
				xo|=(1<<i);
			}
			else{
				an^=(1<<i);	
			}
		}
	}
	printf("3\n");
	printf("& %d\n",an);
	printf("| %d\n",o);
	printf("^ %d\n",xo);
}