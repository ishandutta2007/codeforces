//#include<stdio.h>
//#include<stdlib.h>
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
#define MEM(x) memset(x,0,sizeof(x))
//#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> v;
	for(int i=2;i<=n&&v.size()!=k-1;i++){
		while(n%i==0){
			v.pb(i);
			n/=i;
			if(v.size()==k-1)
			break;
		}
	} 
	if(v.size()==k-1&&n!=1)
	{
		for(int i=0;i<v.size();i++){
			printf("%d ",v[i]); 
		}
		printf("%d\n",n);
	}
	else
	printf("-1\n");
}

/*90 110
180 220
270 330
360 440
450 550
540 660
630 770
*/