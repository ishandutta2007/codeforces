#include<stdio.h>
#include<stdlib.h>
/*#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
//#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;*/
int compare(const void *a, const void *b)
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}             
      else if (c == d) {return 0;}    
      else return 1;                          
}
int main(){
	int n,l,r;
	scanf("%d %d %d",&n,&l,&r);
	int a[100005];
	int b[100005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	scanf("%d",&b[i]);
	qsort(a+l-1,r-l+1,sizeof(a[0]),compare);
	qsort(b+l-1,r-l+1,sizeof(b[0]),compare);
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			printf("LIE\n");
			return 0;
		}
	}
	printf("TRUTH\n");
}/**/
/*
Y  * (5y-4)(y+1)*/