//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define pi 3.14159265359
using namespace std;
int main() {
	int p,y,x;
	scanf("%d %d %d",&p,&y,&x);
	x=y-(y-x)/50*50;
	for(int i=x;;i+=50){
		int ok=0;
		int a=(i/50)%475;
		for(int j=0;j<25;j++){	
			a=(a*96+42)%475;	
			if(a+26==p){
				if(i<=y)
					printf("0\n");
				else
					printf("%d\n",(i-y+50)/100);
					return 0;
			}
		}
	//	printf("%d",i);
	}
}