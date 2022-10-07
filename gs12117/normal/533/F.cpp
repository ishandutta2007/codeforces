#include<stdio.h>
int n,m;
char a[200100];
char b[200100];
int ap[30];
int pa[200100];
int pb[200100];
int ff[200100];
int kmp[200100];
bool match[200100][30][30];
int an;
int ans[200100];
int main(){
	int i,j,k,l;
	scanf("%d%d%s%s",&n,&m,b,a);
	for(i=0;i<26;i++){
		ff[0]=-1;
		for(j=0;j<m;j++){
			if(a[j]=='a'+i){
				pa[j]=1;
				ap[i]=1;
			}
			else pa[j]=0;
			k=ff[j];
			while(k>=0&&pa[k]!=pa[j]){
				k=ff[k];
			}
			ff[j+1]=k+1;
		}
		for(j=0;j<26;j++){
			kmp[0]=0;
			for(k=0;k<n;k++){
				if(b[k]=='a'+j)pb[k]=1;
				else pb[k]=0;
				l=kmp[k];
				while(l>=m||(l>=0&&pa[l]!=pb[k])){
					l=ff[l];
				}
				kmp[k+1]=l+1;
				if(kmp[k+1]==m)match[k-m+1][i][j]=1;
			}
		}
	}
	for(i=0;i<n-m+1;i++){
		for(j=0;j<26;j++){
			if(ap[j]==0)continue;
			for(k=0;k<26;k++){
				if(match[i][j][k]==1){
					if(match[i][k][j]==1)break;
				}
			}
			if(k==26)break;
		}
		if(j==26){
			ans[an]=i;
			an++;
		}
	}
	printf("%d\n",an);
	for(i=0;i<an;i++){
		printf("%d ",ans[i]+1);
	}
}