#include<stdio.h>
char a[10];
int ans;
int pt[10];
int al;
int main(){
	int i,j,t;
	pt[0]=1;
	for(i=0;i<8;i++){
		pt[i+1]=pt[i]*10;
	}
	scanf("%s",a);
	for(i=0;a[i];i++){
		if(a[i]-'0'>ans)ans=a[i]-'0';
	}
	al=i;
	printf("%d\n",ans);
	for(i=0;i<ans;i++){
		t=0;
		for(j=0;a[j];j++){
			if(a[j]-'0'>i){
				t+=pt[al-j-1];
			}
		}
		printf("%d ",t);
	}
}