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
#define N 300005
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main() {
	int a,b;
	scanf("%d %d",&a,&b);
	int i=1;
	for(i=1;a>=0&&b>=0;i++){
		if(i%2==0)
		b-=i;
		else
		a-=i;
	}
	if(i%2==0)
	printf("Vladik");
	else
	printf("Valera");
    return 0;
}