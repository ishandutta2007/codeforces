#include<stdio.h>
int mnsc[1510][1510];
int sc[1510];
char a[1510];
char b[1510];
int n;
int ans;
int main(){
	int i,j,k;
	scanf("%s%s%d",a,b,&n);
	for(i=0;a[i];i++){
		k=0;
		mnsc[i][0]=i-1;
		for(j=i-1;j>=0;){
			while(1){
				if(a[i+k]==a[j+k]){
					k++;
					mnsc[i][k]=j;
				}
				else break;
			}
			if(k>sc[j])break;
			j=mnsc[j][k];
		}
		sc[i]=k;
		k=0;
		for(j=i;a[j];j++){
			if(b[a[j]-'a']=='0')k++;
			if(k>n)break;
		}
		if(j-i>sc[i])ans+=j-i-sc[i];
	}
	printf("%d",ans);
}