#include<stdio.h>
int n;
int a[100100];
long long int ans;
int chk[100100];
int diff[100100];
int occ[100100];
int mocc[100100];
int diffsum;
int moccsum;
int moddsum;
int midp;
void mocccng(int loc,int val){
	if(mocc[loc]<=0)moccsum++;
	if((mocc[loc]+n+n)%2==0)moddsum++;
	mocc[loc]+=val;
	if(mocc[loc]<=0)moccsum--;
	if((mocc[loc]+n+n)%2==0)moddsum--;
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	ans=0;
	for(i=0;i<n;i++){
		if(a[i]!=a[n-i-1])diff[i]=1;
		occ[a[i]]++;
	}
	for(i=0;i<n/2;i++){
		diffsum+=diff[i];
	}
	j=0;
	for(i=1;i<=n;i++){
		if(occ[i]%2==1)j++;
	}
	if(j>1)goto fin;
	j=n;
	for(i=n-1;i>=0;i--){
		while(j>i){
			j--;
			if(j<0)goto fin;
			chk[j]=1;
			if(chk[n-1-j]==0&&diff[j]==1)diffsum--;
			if(chk[n-1-j]==0){
				mocccng(a[n-1-j],1);
			}
			else if(n%2==0||j!=n/2){
				mocccng(a[j],-1);
			}
			mocccng(a[j],-1);
		}
		while(1){
			if(diffsum==0&&moccsum==0&&(moddsum==0||(moddsum==1&&j<=n/2&&i>=n/2)))break;
			j--;
			if(j<0)goto fin;
			chk[j]=1;
			if(chk[n-1-j]==0&&diff[j]==1)diffsum--;
			if(chk[n-1-j]==0){
				mocccng(a[n-1-j],1);
			}
			else if(n%2==0||j!=n/2){
				mocccng(a[j],-1);
			}
			mocccng(a[j],-1);
		}
		ans+=j+1;
		chk[i]=0;
		if(chk[n-1-i]==0&&diff[i]==1)diffsum++;
		if(chk[n-1-i]==1){
			mocccng(a[i],1);
		}
		else if(n%2==0||i!=n/2){
			mocccng(a[n-1-i],-1);
		}
		mocccng(a[i],1);
	}
fin:
	printf("%I64d",ans);
}