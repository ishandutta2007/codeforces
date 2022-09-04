#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define N 1000005
#define sqr(x) ((x)*(x))
#define EPS 1e-11
using namespace std;
typedef long long ll;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a=240-k;
	int ans=0,sum=0;
	for(int i=0;i<n;i++,ans++){
		if((i+1)*5+sum<=a)
		sum+=(i+1)*5;
		else
		break;
	}
	printf("%d\n",ans);
}