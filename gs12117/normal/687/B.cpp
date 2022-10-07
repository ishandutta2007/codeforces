#include<stdio.h>
int n,m;
int c[1001000];
int ans;
int mgcd(int x,int y){
	if(x==0)return y;
	return mgcd(y%x,x);
}
int mlcm(int x,int y){
	long long int res=x;
	res*=y;
	res/=mgcd(x,y);
	return res;
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	ans=1;
	for(i=0;i<n;i++){
		ans=mlcm(ans,mgcd(c[i],m));
	}
	if(ans==m)puts("Yes");
	else puts("No");
	return 0;
}