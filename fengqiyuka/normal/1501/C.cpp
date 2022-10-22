#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+100,M=2600000;
int a[N],b1[M],b2[M],h[N],p[N];
bool cmp(int n1,int n2) {return (n1<n2);}
bool cmp2(int n1,int n2) {return (a[n1]<a[n2]);}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),h[i]=i;
	sort(h+1,h+n+1,cmp2);
	sort(a+1,a+n+1,cmp);
	if(n>8000) n=8000;
	memset(b1,0,sizeof(b1));
	memset(b2,0,sizeof(b2));
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			b1[a[i]-a[j]]++;
	bool pd=false;int w,x,y,z,Ans;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) b1[a[j]-a[i]]--;
		for(int j=1;j<i;j++)
			if(b1[a[i]-a[j]]>0){
				w=i;x=j;Ans=a[i]-a[j];
				pd=true;break;
			}
		if(pd) break;
	}
	if(!pd){
		printf("NO\n");
		return 0;
	}
	pd=false;
	for(int i=w+1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			if(a[j]-a[i]==Ans){
				z=j;y=i;
				pd=true;break;
			}
		if(pd) break;
	}
	printf("YES\n");
	printf("%d %d %d %d\n",h[x],h[z],h[w],h[y]);
	return 0;
}