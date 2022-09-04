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
int main() {
	int n;
	scanf("%d",&n);
	int ok=1;
	int a[1005],b[1050];
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		if(a[i]!=b[i])
		ok=0;
	}
	if(!ok)
	printf("rated\n");
	else{
		for(int i=1;i<n;i++)
			if(a[i]>a[i-1])
				ok=0;
		printf("%s\n",!ok?"unrated":"maybe");
	}return 0;
}