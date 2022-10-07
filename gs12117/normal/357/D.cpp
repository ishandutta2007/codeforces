#include<stdio.h>
long long int n,m;
char a[1001000];
char b[1001000];
long long int cchk[1001000][26];
long long int al,bl;
long long int gcd,lcm,rep,ans;
long long int gcdf(long long int x,long long int y){
	if(y==0)return x;
	return gcdf(y,x%y);
}
int main(){
	long long int i,j;
	scanf("%I64d%I64d",&n,&m);
	scanf("%s%s",a,b);
	for(al=0;a[al];al++);
	for(bl=0;b[bl];bl++);
	gcd=gcdf(al,bl);
	lcm=al*bl/gcd;
	rep=al*n/lcm;
	for(i=0;i<al;i++){
		cchk[i%gcd][a[i]-'a']++;
	}
	for(i=0;i<bl;i++){
		ans+=cchk[i%gcd][b[i]-'a'];
	}
	ans*=rep;
	printf("%I64d",n*al-ans);
}