#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+100;
struct node{
	int x,y,id;
}g[N];

bool cmp1(node n1,node n2) {return (n1.x<n2.x);}
bool cmp2(node n1,node n2) {return (n1.y<n2.y);}
bool cmp3(node n1,node n2) {return (n1.id<n2.id);}

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		
		for(int i=1;i<=n;i++) scanf("%d",&g[i].x);
		for(int i=1;i<=n;i++) scanf("%d",&g[i].y);
		for(int i=1;i<=n;i++) g[i].id=i;
		
		sort(g+1,g+n+1,cmp1);
		for(int i=1;i<=n;i++) g[i].x=i;
		sort(g+1,g+n+1,cmp2);
		for(int i=1;i<=n;i++) g[i].y=i;
		sort(g+1,g+n+1,cmp1);
		int Min=2e9;
		for(int i=n;i>=1;i--){
			if(Min>g[i].y) Min=g[i].y;
			if(i==Min) break;
		}
		sort(g+1,g+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(g[i].x>=Min||g[i].y>=Min) printf("1");
			else printf("0");
		}
		printf("\n");
	}
	
	
	return 0;
}