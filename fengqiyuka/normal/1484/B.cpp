#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+100;
int a[N];
int abs(int x){
	if(x<0) return -x;
	return x;
}
int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int m=-1,c=a[2]-a[1];bool pd=true;
		for(int i=3;i<=n;i++){
			int t=a[i]-a[i-1];
			if(t!=c){
				int t2=abs(t-c);
				if(m==-1) m=t2;
				else if(m!=t2) {pd=false;break;}
			}
		}
		if(m==-1){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=m) {pd=false;break;}
		}
		if(!pd) printf("-1\n");
		else{
			if(c<0) c+=m;
			if(n>=2) printf("%d %d\n",m,c);
			else printf("%d 0\n",m);
		}
	}
	return 0;
}