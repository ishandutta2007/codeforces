#include<bits/stdc++.h>
using namespace std;

const int N=2010;
char s[N];int a[N][N],sta[N];

int main()
{
	
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=n-i+1;j++)
				a[i][i+j-1]=s[j]-'0';
		}
		
		int tot=1;sta[1]=1;
		for(int i=2;i<=n;i++){
			for(int j=tot;j>=1;j--){
				bool pd=false;
				for(int k=sta[j];k>sta[j-1];k--)
					if(a[k][i]){
//						printf("%d %d\n",k,i);
						sta[j]=k;pd=true;break;
					}
				if(pd){
					if(tot>=j){
						sta[tot+1]=i;
						
						if((tot+1)%2==j%2){
							for(int k=j+2;k<=tot-1;k+=2) printf("%d %d\n",sta[k],sta[k+2]);
							printf("%d %d\n",sta[tot+1],sta[j]);
							printf("%d %d\n",sta[tot],sta[j]);
							for(int k=tot;k>=j+3;k-=2) printf("%d %d\n",sta[k],sta[k-2]);
						}
						else{
							for(int k=tot;k>=j+2;k-=2) printf("%d %d\n",sta[k],sta[k-2]);
							printf("%d %d\n",sta[j],sta[tot+1]);
							for(int k=tot+1;k>=j+3;k-=2) printf("%d %d\n",sta[k],sta[k-2]);
						}
					}
					tot=j-1;
				}
			}
			sta[++tot]=i;
		}
	}
	
	return 0;
}