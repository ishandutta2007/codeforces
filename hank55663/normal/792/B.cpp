#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	queue<int> q;
	for(int i=1;i<=n;i++)
	q.push(i);
	for(int i=0;i<k;i++){
		int a;
		scanf("%d",&a);
		a%=n;
		while(a--)
		q.push(q.front()),q.pop();
		if(i!=0)
		printf(" ");
		printf("%d",q.front());
		q.pop();
		n--;
	}
	printf("\n");
}