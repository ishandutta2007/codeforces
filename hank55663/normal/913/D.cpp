#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
#define N 200005
using namespace std;
typedef long long LL;
int main(){
	pair<pii,int> p[N];
	vector<pii> v[N];
	int n,t;
	scanf("%d %d",&n,&t);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
	//	a=n,b=1;
		p[i]=mp(mp(b,a),i);
	}
	sort(p,p+n);
	int Max=n+1,Min=0;
	while(Min+1<Max){
		int mid=(Max+Min)/2;
		int cnt=0;
		int k=0;
		for(int i=0;i<n;i++){
			if(p[i].x.y>=mid){
				if(k+p[i].x.x>t){
					break;
				}
				cnt++;
				k+=p[i].x.x;
			}
		}
		if(cnt>=mid){
			Min=mid;
		}
		else{
			Max=mid;
		}
	}
	printf("%d\n",Min);
	printf("%d\n",Min);
	int k=Min;
	for(int i=0;i<n;i++){	
		if(Min==0)
		break;
		if(p[i].x.y>=k){
			printf("%d ",p[i].y+1);
			Min--;
		}
	
	}
}