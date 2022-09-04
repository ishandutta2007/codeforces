#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	pair<pii,int> p[400005];
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[2*i]=mp(mp(x,0),i);
		p[2*i+1]=mp(mp(y+1,-1),i); 
	} 
	sort(p,p+2*n);
	set<int> s;
	int ok[200005];
	MEM(ok);
	for(int i=0;i<2*n;i++){
		if(i!=0&&s.size()==1&&p[i].x.x!=p[i-1].x.x)
		ok[*s.begin()]=1;
		if(p[i].x.y==0)
		s.insert(p[i].y);
		else
		s.erase(p[i].y);
	}
	for(int i=0;i<n;i++){
		if(!ok[i]){
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("-1\n");
}
/*3 2 6 5 4 1
1 3 2 6 5 4*/