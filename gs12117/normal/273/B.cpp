#include<stdio.h>
int n,m;
int a[100100];
int b[100100];
int c[200100];
int tmp[200100];
long long int fact[200100];
long long int tpow[200100];
long long int ans;
void sort(int start,int end){
	if(end-start<2)return;
	int mid=(start+end)/2;
	sort(start,mid);
	sort(mid,end);
	int i,j,k;
	i=start;
	j=mid;
	k=start;
	for(;i<mid&&j<end;k++){
		if(c[i]<c[j]){
			tmp[k]=c[i];
			i++;
		}
		else{
			tmp[k]=c[j];
			j++;
		}
	}
	for(;i<mid;k++){
		tmp[k]=c[i];
		i++;
	}
	for(i=start;i<k;i++){
		c[i]=tmp[i];
	}
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d\n",&a[i]);
	}
	j=0;
	for(i=0;i<n;i++){
		scanf("%d\n",&b[i]);
		if(a[i]==b[i])j++;
	}
	scanf("%d",&m);
	fact[0]=1;
	tpow[0]=1;
	for(i=1;i<200010;i++){
		if(i%2==1)fact[i]=fact[i-1]*i;
		else fact[i]=fact[i-1]*i/2;
		fact[i]%=m;
		tpow[i]=tpow[i-1]*2;
		tpow[i]%=m;
	}
	for(i=0;i<n;i++){
		c[i]=a[i];
	}
	for(i=0;i<n;i++){
		c[i+n]=b[i];
	}
	sort(0,2*n);
	k=1;
	ans=1;
	for(i=1;i<2*n;i++){
		if(c[i]==c[i-1]){
			k++;
		}
		else{
			ans*=fact[k];
			ans%=m;
			if(j==0){
				ans*=tpow[k/2];
			}
			else if(k/2-j>0){
				ans*=tpow[k/2-j];
				j=0;
			}
			else{
				j-=k/2;
			}
			ans%=m;
			k=1;
		}
	}
	ans*=fact[k];
	ans%=m;
	if(j==0){
		ans*=tpow[k/2];
	}
	else if(k/2-j>0){
		ans*=tpow[k/2-j];
		j=0;
	}
	else{
		j-=k/2;
	}
	ans%=m;
	printf("%I64d",ans);
}