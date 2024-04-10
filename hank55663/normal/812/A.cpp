#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int a[4][4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	int ok=0;
	for(int i=0;i<4;i++)
		if(a[i][3]==1){
			ok|=a[(i+1)%4][0];
			ok|=a[(i+2)%4][1];
			ok|=a[(i+3)%4][2];
			ok|=a[i][0]|a[i][1]|a[i][2];
		}
	if(ok)
	printf("YES\n");
	else
	printf("NO\n");
}