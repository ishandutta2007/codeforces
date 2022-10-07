#include<stdio.h>
int mod=1000000007;
int a[10];
int lnum(int n){
	if(n==0)return 0;
	if(n%10==4||n%10==7)return lnum(n/10)+1;
	else return lnum(n/10);
}
long long int f(int n,int m){
	if(n==0)return 0;
	if(m<0)return 0;
	int k;
	if(n%10>7)k=2;
	else if(n%10>4)k=1;
	else k=0;
	if(lnum(n/10)==m){
		return (n%10-k+f(n/10,m-1)*2+f(n/10,m)*8)%mod;;
	}
	if(lnum(n/10)==m-1){
		return (k+f(n/10,m-1)*2+f(n/10,m)*8)%mod;;
	}
	return (f(n/10,m-1)*2+f(n/10,m)*8)%mod;
}
long long int perm(int n){
	long long int k=0;
	long long int j[6];
	int i[6];
	for(i[0]=0;i[0]<n;i[0]++){
		j[0]=a[i[0]];
		a[i[0]]--;
		n-=i[0];
	for(i[1]=0;i[1]<n;i[1]++){
		j[1]=j[0]*a[i[1]]%mod;
		a[i[1]]--;
		n-=i[1];
	for(i[2]=0;i[2]<n;i[2]++){
		j[2]=j[1]*a[i[2]]%mod;
		a[i[2]]--;
		n-=i[2];
	for(i[3]=0;i[3]<n;i[3]++){
		j[3]=j[2]*a[i[3]]%mod;
		a[i[3]]--;
		n-=i[3];
	for(i[4]=0;i[4]<n;i[4]++){
		j[4]=j[3]*a[i[4]]%mod;
		a[i[4]]--;
		n-=i[4];
	for(i[5]=0;i[5]<n;i[5]++){
		j[5]=j[4]*a[i[5]]%mod;
		k+=j[5];
	}
		a[i[4]]++;
		n+=i[4];
	}
		a[i[3]]++;
		n+=i[3];
	}
		a[i[2]]++;
		n+=i[2];
	}
		a[i[1]]++;
		n+=i[1];
	}
		a[i[0]]++;
		n+=i[0];
	}
	return k%mod;
}
int main(){
	int n,i,j;
	long long int ans=0;
	scanf("%d",&n);
	for(i=0;i<10;i++){
		a[i]=f(n+1,i);
	}
	a[0]--;
	j=0;
	for(i=0;i<10;i++){
		ans+=(perm(i)*a[i])%mod;
	}
	printf("%d",(int)(ans%mod));
}