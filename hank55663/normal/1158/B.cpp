#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	/*if(n==k){
		for(int i = 0;i<n;i++)
		printf("1");
		printf("\n");
		return 0;
	}*/
	int cnt = (n-k)/2+1;
	for(int i = 1;i<=n;i++){
		if(i%cnt==0){
			printf("0");
		}
		else{
			printf("1");
		}
	}
	printf("\n");
	return 0;
}
/*
n = x*m+x=x*(m+1);



*/