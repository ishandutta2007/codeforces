#include<stdio.h>
long long int x,y,m,t;
long long int ans;
long long int f(){
	if(x>=m||y>=m){
		return 0;
	}
	if(x>y){
		t=x;
		x=y;
		y=t;
	}
	x+=y;
	return f()+1;
}
int main(){
	scanf("%I64d%I64d%I64d",&x,&y,&m);
	if(x>=m||y>=m){
		printf("0");
		return 0;
	}
	if(x<=0&&y<=0){
		printf("-1");
		return 0;
	}
	if(x>y){
		t=x;
		x=y;
		y=t;
	}
	if(x<=0){
		ans+=(-x)/y;
		x+=y*((-x)/y);
		while(x<=0){
			x+=y;
			ans++;
		}
	}
	ans+=f();
	printf("%I64d",ans);
}