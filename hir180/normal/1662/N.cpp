#include <bits/stdc++.h>
#define SIZE 1505
using namespace std;
typedef long long int ll;

int X[SIZE*SIZE],Y[SIZE*SIZE];
int cx[SIZE],cy[SIZE];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int a;
			scanf("%d",&a);a--;
			X[a]=i,Y[a]=j;
		}
	}
	ll ret=0;
	for(int i=0;i<n*n;i++){
		ret+=cx[X[i]]*(n-cy[Y[i]]-1);
		ret+=(n-cx[X[i]]-1)*cy[Y[i]];
		cx[X[i]]++,cy[Y[i]]++;
	}
	printf("%lld\n",ret/2);
}