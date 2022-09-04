#include<bits/stdc++.h>
#define time Time
#define pii pair<int,int>    
#define x first    
#define y second 
#define N 10000005   
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))    
#define sqr(x) ((x)*(x))
typedef long long LL;  
using namespace std;
const int mod=1e9+7;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		
		printf("%d\n",n/2);
		if(n==3)
		printf("3");
		else
		printf("2");
		for(int i=2;i<n/2;i++)
		printf(" 2");
		if(n%2==0&&n!=2)
		printf(" 2");
		else if(n!=2&&n!=3)
		printf(" 3");
		printf("\n");
	}
}
/*

 1 - 1 + 2 + 10 - 2 + 3  + 5
 1  - 2  - 3  
*/