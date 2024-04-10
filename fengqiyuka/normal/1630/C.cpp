#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e5+100;
int a[N],Min[N],Max[N];

struct node{
	int l,r;
}g[N],p[N];

bool cmp(node n1,node n2) {return (n1.l<n2.l);}
int mymax(int x,int y) {return (x>y?x:y);}

int main()
{
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<=n;i++) Min[i]=1e9,Max[i]=-1e9;
	for(int i=1;i<=n;i++){
		if(Min[a[i]]>i) Min[a[i]]=i;
		if(Max[a[i]]<i) Max[a[i]]=i;
	}
	
	int tot=0;
	for(int i=1;i<=n;i++)
		if(Min[i]<Max[i]) g[++tot].l=Min[i],g[tot].r=Max[i];
	if(tot==0){
		printf("0\n");
		return 0;
	}
		
	sort(g+1,g+tot+1,cmp);
	
	int tot2=0,Max1=0;
	for(int i=1;i<=tot;i++){
		if(g[i].r>Max1) p[++tot2]=g[i];
		if(Max1<g[i].r) Max1=g[i].r;
	}
	
	int Sum2=0;
	for(int i=1;i<=tot2;i++)
		Sum2=Sum2+p[i].r-mymax(p[i].l-1,p[i-1].r);
	
	int Sum=2,id=1;
	for(int i=2;i<=tot2;i++){
		if(p[i].l>p[id].r){
			Sum+=2;
			id=i;
		}
		else if(i==tot2||p[i+1].l>p[id].r){
			Sum++;
			id=i;
		}
	}
	
	printf("%d\n",Sum2-Sum);
	
	return 0;
}