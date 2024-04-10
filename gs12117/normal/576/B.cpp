#include<stdio.h>
int n;
int perm[100100];
int chk[100100];
int p[100100];
int pn;
int main(){
	int i,flag=0;
	int center;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&perm[i]);
		perm[i]--;
		if(perm[i]==i){
			flag=1;
			center=i;
		}
	}
	if(flag==1){
		puts("YES");
		for(i=0;i<n;i++){
			if(i!=center){
				printf("%d %d\n",i+1,center+1);
			}
		}
	}
	else{
		for(i=0;i<n;i++){
			if(perm[perm[i]]==i)break;
		}
		center=i;
		chk[center]=-1;
		chk[perm[center]]=1;
		for(i=0;i<n;i++){
			if(chk[i]==0){
				int j=i;
				int k=0;
				while(chk[j]==0){
					chk[j]=k+1;
					k++;
					j=perm[j];
				}
				if(k%2==1){
					puts("NO");
					return 0;
				}
			}
		}
		puts("YES");
		for(i=0;i<n;i++){
			if(i!=center){
				printf("%d %d\n",chk[i]%2?center+1:perm[center]+1,i+1);
			}
		}
	}
}