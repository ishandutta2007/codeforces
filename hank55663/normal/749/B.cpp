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
	int x[3],y[3];
	for(int i=0;i<3;i++)
	scanf("%d %d",&x[i],&y[i]);
	printf("3\n");
	printf("%d %d\n",x[1]+x[2]-x[0],y[1]+y[2]-y[0]);
	printf("%d %d\n",x[2]+x[0]-x[1],y[2]+y[0]-y[1]);
	printf("%d %d\n",x[0]+x[1]-x[2],y[0]+y[1]-y[2]);
}
/*

 1 - 1 + 2 + 10 - 2 + 3  + 5
 1  - 2  - 3  
*/