#pragma (-Ofast )
#pragma unroll
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
#define N 500005
vector<int> v[5][1005];
int mod=1e9+7;
int main(){
	int n;
	scanf("%d",&n);
	pii p[150005];
	for(int i=0;i<n;i++){
		scanf("%d %d",&p[i].x,&p[i].y);
	}
	vector<int> v;
	int k=p[0].x;
	for(int t=0;t<2;t++){
		for(int i=2;i<1e5;i++){
			if(k%i==0){
				v.pb(i);
				while(k%i==0)
					k/=i;
			}
		}
		if(k!=1)
		v.pb(k);
		k=p[0].y;
	}
	for(auto it:v){
		int ok=1;
		for(int i=0;i<n;i++){
			if(p[i].y%it!=0&&p[i].x%it!=0){
				ok=0;
				break;
			}
		}
		if(ok){
			printf("%d\n",it);
			return 0;
		}
	}
	printf("-1\n");
}
/*
1 2 3 3 2 1 =6
1 2 4       12
1 3 3       3
1 3 4       8
2 2 3       4
2 2 4       9
2 3 3       2
2 3 4       6

*/