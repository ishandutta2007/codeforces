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
	long long int ma=1e18,mi=-1e18;
	int n;
	scanf("%d",&n);
	int ok=1;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(b==2){
			ma=min(1899ll,ma);
		}
		else if(b==1){
			mi=max(mi,1900ll);
		}
		if(ma<mi)
		ok=0;
		ma+=a;
		mi+=a;
	//	printf("%I64d %d\n",ma,mi);
	}
	if(!ok)
	printf("Impossible\n");
	else if(ma>1e10)
	printf("Infinity\n");
	else
	printf("%I64d\n",ma);
}