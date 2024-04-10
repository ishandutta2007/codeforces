#include<cstdio>
#include<cstring>
using namespace std;

const int N=1e6+100;
int a[N],qz[N];

int mymin(int x,int y) {return (x<y?x:y);}

int main()
{
	int T;
	scanf("%d",&T);
	
	memset(qz,0,sizeof(qz));
	
	while(T--){
		int n,c;scanf("%d%d",&n,&c);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),qz[a[i]]++;
		
		for(int i=1;i<=c;i++) qz[i]+=qz[i-1];
		
		bool pd=true;
		for(int i=1;i<=c;i++){
			int t=qz[i]-qz[i-1];
			if(t==0) continue;
			for(int j=1;j<=c/i;j++){
				int t1=qz[j]-qz[j-1];
				int t2=qz[mymin(c,(j+1)*i-1)]-qz[j*i-1];
				if(t2>0&&t1==0) {pd=false;break;}
			}
			if(!pd) break;
		}
		
		if(pd) printf("Yes\n");
		else printf("No\n");
		
		for(int i=1;i<=c;i++) qz[i]=0;
	}
	
	return 0;
}