#include<stdio.h>
#include<algorithm>
int n;
int p[310];
char a[310][310];
int m[310];
int d[310];
int ccn;
int chk[310];
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<n;i++){
		if(chk[i]==0){
			chk[i]=1;
			ccn=1;
			m[0]=i;
			for(j=0;j<ccn;j++){
				for(k=0;k<n;k++){
					if(a[m[j]][k]=='1'&&chk[k]==0){
						chk[k]=1;
						m[ccn]=k;
						ccn++;
					}
				}
			}
			std::sort(m,m+ccn);
			for(j=0;j<ccn;j++){
				d[j]=p[m[j]];
			}
			std::sort(d,d+ccn);
			for(j=0;j<ccn;j++){
				p[m[j]]=d[j];
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
}