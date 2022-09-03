#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[505][505];
	int b[505][505];
	for(int i = 0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(int i = 0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&b[i][j]);
	for(int i =0;i<n;i++)
		for(int j =0;j<m;j++){
			if(a[i][j]!=b[i][j]){
				if(j==m-1){
					printf("No\n");
					return 0;
				}
				if(i==n-1){
					printf("No\n");
					return 0;
				}
				a[i][j]^=1;
				a[i+1][j]^=1;
				a[i][j+1]^=1;
				a[i+1][j+1]^=1;
			}
		}
	printf("Yes\n");
}
//y-x^2 = bx+c
// A= Bb+Cc
// D= Eb+Fc