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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
vector<pdd> v;
vector<int> ans;
vector<vector<int> > star;
int index;
double len;
void dfs(pdd start,int n){
	vector<int> point;
	if(n==0)
	return ;
	int stind=index;
	point.pb(stind);
	++index;
	ans.pb(index);
	pdd p2=mp(start.x-len*sin(pi/10),start.y-len*cos(pi/10));
	v.pb(p2);
	point.pb(index);
	dfs(p2,n-1);
	++index;
	ans.pb(index);
	pdd p3=mp(start.x+len/2,start.y-tan(pi/5)*len/2);
	v.pb(p3);
	point.pb(index);
	++index;
	ans.pb(index);
	pdd p4=mp(start.x-len/2,start.y-tan(pi/5)*len/2);
	v.pb(p4);
	point.pb(index);
	++index;
	ans.pb(index);
	pdd p5=mp(start.x+len*sin(pi/10),start.y-len*cos(pi/10));
	v.pb(p5);
	ans.pb(stind);
	point.pb(index);
	swap(point[1],point[3]);
	swap(point[3],point[2]);
	swap(point[3],point[4]);
	star.pb(point);
}
int main(){
	int n;
	scanf("%d",&n);
	len=20*cos(pi/5);
	v.pb(mp(0,0));
	ans.pb(1);
	index=1;
	dfs(mp(0,0),n);	
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++){
		printf("%.10lf %.10lf\n",v[i].x,v[i].y);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++)
		printf("%d ",star[i][j]);
		printf("\n");
	}
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
}
/*
910~010  901~001 20
1
110 101 011
10~19 01~91 19
*/