#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;


int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==0 && n==1){
		printf("1\n");
		return 0;
	}
	if(n==1){
		printf("-1\n");
		return 0;
	}
	if(k<n/2){
		printf("-1\n");
		return 0;
	}else{
		FOR(i,0,n/2-1) printf("%d %d ",2*i+1,2*i+2);
		int rem = k-(n/2-1);
		if(rem>n+1){ 
			printf("%d %d ",rem,2*rem);
			if(n%2!=0) printf("1000000000\n");
			else printf("\n");
		}
		else{
			printf("%d %d ",n+rem-(n%rem),n+2*rem-(n%rem));
			if(n%2!=0) printf("1000000000\n");
			else printf("\n");
		}
		
	}
	return 0;
}