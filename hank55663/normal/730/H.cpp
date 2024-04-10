#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	char c[105][105];
	for(int i=0;i<n;i++)
	scanf("%s",c[i]);
	int a[105];
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
		a[i]--;
	}
	char ans[105];
	memset(ans,0,sizeof(ans));
	for(int i=0;;i++){
		if(c[a[0]][i]==0){
			for(int j=1;j<m;j++)
			if(c[a[j]][i]!=0)
			{
				printf("No\n");
				return 0;
			}
			break;
		} 
		char cc=c[a[0]][i];
		for(int j=1;j<m;j++){
			if(c[a[j]][i]==0){
				printf("No\n");
				return 0;
			}
			if(c[a[j]][i]!=cc)
			cc='?';
		}
		ans[i]=cc;
	}
	for(int i=0,j=0;i<n;i++){
		if(i==a[j]){
			j++;
			continue;
		}
		int ok=0;
		for(int k=0;;k++){
			if(ans[k]==0){
				if(c[i][k]!=0)
				ok=1;
			//	printf("%c %d",c[i][k],k);
				break;
			}
			if((ans[k]!='?'&&c[i][k]!=ans[k])||c[i][k]==0)
			ok=1;
		}
		if(!ok){
		printf("No\n");
		return 0;
		}
	}
	printf("Yes\n%s",ans);
}