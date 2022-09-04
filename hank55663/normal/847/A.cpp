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
#define list List
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	pii p[105];
	queue<int> head;
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
		if(x==0)
		head.push(i);
	}
	pii pp[105];
	int index=0;
	while(!head.empty()){
		int x=head.front();
		head.pop();
		int y=x;
		while(p[x].y!=0){
			x=p[x].y;
		}
		pp[index++]=mp(y,x);
	}
	for(int i=0;i<index-1;i++){
		p[pp[i].y].y=pp[i+1].x;
		p[pp[i+1].x].x=pp[i].y;
	}
	for(int i=1;i<=n;i++){
		printf("%d %d\n",p[i].x,p[i].y);
	}
}