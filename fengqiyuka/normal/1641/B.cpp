#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;

const int N=510;
int Ans[3*N*N],tot,Ans2[2*N*N][2],tot2;

map<int,int> B;int a[N];

int main()
{
	
	int T;scanf("%d",&T);
	
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		for(int i=1;i<=n;i++) B[a[i]]=B[a[i]]+1;
		bool pd=true;
		for(int i=1;i<=n;i++){
			if(B[a[i]]%2==1) {pd=false;break;}
		}
		
		for(int i=1;i<=n;i++) B[a[i]]=0;
		
		if(!pd){
			printf("-1\n");
			continue;
		}
		
		tot=0;tot2=0;int las=0;
		while(1){
			int Sum=0,id1=-1,id2=-1;
			for(int i=1;i<=n;i++){
				if(a[i]!=a[i-1]) Sum=0;
				Sum++;
				if(Sum%2==1&&a[i]!=a[i+1]){
					if(id1==-1) id1=i;
					else if(id2==-1&&a[i]==a[id1]) {id2=i;break;}
				}
			}
			
			if(id1==-1) break;
			
			Ans[++tot]=id1*2;
			for(int i=1;i<=id1;i++){
				Ans2[++tot2][0]=las+id1+i-1;
				Ans2[tot2][1]=a[i];
			}
			las=las+2*id1;
			
			for(int i=1;i<=id1/2;i++) swap(a[i],a[id1+1-i]);
			
			Ans[++tot]=2*(id2-1);
			for(int i=1;i<id2;i++){
				Ans2[++tot2][0]=las+id2-1+i-1;
				Ans2[tot2][1]=a[i];
			}
			
			for(int i=1;i<=(id2-1)/2;i++) swap(a[i],a[id2-i]);
			las=las+2*(id2-1);
		}
		
		for(int i=1;i<=n/2;i++) Ans[++tot]=2;
		
		printf("%d\n",tot2);
		for(int i=1;i<=tot2;i++) printf("%d %d\n",Ans2[i][0],Ans2[i][1]);
		
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++) printf("%d ",Ans[i]);
		printf("\n");
	}
	
	return 0;
}