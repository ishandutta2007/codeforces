#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=5100;
int a[N],b[N],fa[N];
int mymax(int x,int y) {return x>y?x:y;}
int mymin(int x,int y) {return x<y?x:y;}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++) fa[i]=i;
		ll Ans=a[n]-1;b[n]=a[n]-1;
		/*for(int i=n-1;i>=1;i--){
			if(i==8){
				i++;i--;
			}
			for(int j=i+1;j<=i+a[i]&&j<=n;j++){
				if(b[j]) b[j]--,b[i]++;
				else if(j!=i+1) b[i]++,Ans++;
			}
			int t=mymax(a[i]-(n-i),0);
			b[i]=b[i]+t;
			Ans=Ans+t;
		}*/
		ll Ans2=0;
		for(int i=1;i<=n;i++){
			Ans2=Ans2+mymax(a[i]-(n-i),0);
			a[i]=mymin(a[i],n-i);
			while(a[i]>1){
				int t=i;Ans2++;
				while(t<=n){
					int t2=a[t];
					a[t]=mymax(a[t]-1,1);
					if(fa[t]==t&&a[t]==1&&t!=n) fa[t]=t+1;
					if(t2==1&&t!=n) t=find(t);
					else t=t+t2;
				}
			}
		}
		//printf("%lld\n",Ans);
		printf("%lld\n",Ans2-1);
	}
	return 0;
}