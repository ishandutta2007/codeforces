#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N=1e5+100;
struct node{
	int co,x,y;
}tr[N];int tot=0;

bool cmp1(node n1,node n2){
	if(n1.co==n2.co) return (n1.x<n2.x);
	return (n1.co<n2.co);
}
bool cmp2(node n1,node n2){
	if(n1.co==n2.co) return (n1.y<n2.y);
	return (n1.co<n2.co);
}


int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	int tot=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x;scanf("%d",&x);
			tr[++tot].co=x;tr[tot].x=i;tr[tot].y=j;
		}
		
	sort(tr+1,tr+tot+1,cmp1);
	
	ll Ans=0;int las=0;
	for(int i=1;i<=tot;i++){
		if(i==tot||tr[i].co!=tr[i+1].co){
			int Sum=i-las;
			for(int j=las+1;j<=i;j++){
				Ans=Ans+(ll)tr[j].x*((j-las-1)-(i-j));
			}
			las=i;
		}
	}
	
	sort(tr+1,tr+tot+1,cmp2);
	las=0;
	for(int i=1;i<=tot;i++){
		if(i==tot||tr[i].co!=tr[i+1].co){
			int Sum=i-las;
			for(int j=las+1;j<=i;j++){
				Ans=Ans+(ll)tr[j].y*((j-las-1)-(i-j));
			}
			las=i;
		}
	}
	
	printf("%lld\n",Ans);
	return 0;
}