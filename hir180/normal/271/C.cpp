#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	if(k*3>n){
		puts("-1");
		return 0;
	}
	if(k%2==0){
		for(int i=1;i<=k;i++){
			printf("%d ",i);
		}
		for(int i=k;i>=1;i--){
			printf("%d ",i);
		}
		for(int i=1;i<=k;i++){
			printf("%d%c",i,i+2*k==n?'\n':' ');
		}
		for(int i=1;i<=n-k*3;i++){
			printf("%d%c",1,i==n-k*3?'\n':' ');
		}
	}else{
		for(int i=1;i<=k;i++){
			printf("%d ",i);
		}
		for(int i=k;i>=1;i--){
			printf("%d ",i);
		}
		for(int i=1;i<=(k-1)/2;i++){
			printf("%d ",i);
		}
		printf("%d %d ",(k+1)/2+1,(k+1)/2);
		for(int i=(k+5)/2;i<=k;i++){
			printf("%d%c",i,i+2*k==n?'\n':' ');
		}
		for(int i=1;i<=n-k*3;i++){
			printf("%d%c",1,i==n-k*3?'\n':' ');
		}		
	}
	scanf("\n");
	return 0;
}