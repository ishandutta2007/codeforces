#include<stdio.h>
int n,m;
int a[110];
int b[310];
int ans;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(m<5*n){
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				for(k=0;k<a[j];k++){
					if(b[k]>b[a[j]])b[a[j]]=b[k];
				}
				b[a[j]]++;
			}
		}
	}
	else{
		for(i=0;i<2*n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<a[j];k++){
					if(b[k]>b[a[j]])b[a[j]]=b[k];
				}
				b[a[j]]++;
			}
		}
		for(i=0;i<n;i++){
			b[a[i]]+=m-4*n;
		}
		for(i=0;i<2*n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<a[j];k++){
					if(b[k]>b[a[j]])b[a[j]]=b[k];
				}
				b[a[j]]++;
			}
		}
	}
	ans=0;
	for(i=0;i<305;i++){
		if(b[i]>ans)ans=b[i];
	}
	printf("%d",ans);
}