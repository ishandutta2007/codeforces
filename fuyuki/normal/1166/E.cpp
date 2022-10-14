#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
bitset<10000>a[50];
int n,m,k,x;
int main(){
	scanf("%d%d",&m,&n);
	FOR(i,0,m-1)for(scanf("%d",&k);k--;a[i][x]=1)scanf("%d",&x);
	FOR(i,0,m-1)FOR(j,i+1,m-1)if(!(a[i]&a[j]).count())return!printf("impossible");
	return!printf("possible");
}