#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int main(){
	int h1,a1,c1;
	int h2,a2;
	scanf("%d %d %d %d %d",&h1,&a1,&c1,&h2,&a2);
	vector<int> v;
	while(h2>0){
		if(h1>a2||h2<=a1){
			h2-=a1;
			h1-=a2;
			v.pb(0);
		}
		else{
			h1=h1+c1-a2;
			v.pb(1); 
		}
	}
	printf("%d\n",v.size());
	for(auto it=v.begin();it!=v.end();it++){
		if(*it)
		printf("HEAL\n");
		else
		printf("STRIKE\n");
	}
}