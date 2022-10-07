#include<stdio.h>
int n,m;
int mod=1000000009;
long long int fib[1<<20];
int a[300100];
struct fnc{
	long long int a,b,g,s;
	fnc operator+(const fnc&r)const{
		fnc d;
		d.g=g+r.g;
		d.a=a*fib[r.g+3]+b*fib[r.g+2]+r.a;
		d.b=a*fib[r.g+2]+b*fib[r.g+1]+r.b;
		d.s=s+r.s+(a*(fib[r.g+4]+mod-1))+(b*(fib[r.g+3]+mod-1));
		d.a%=mod;
		d.b%=mod;
		d.s%=mod;
		return d;
	}
};
fnc it[1<<20];
void ks(int loc){
	if(loc==0)return;
	if(loc<(1<<19)){
		it[loc]=it[loc*2]+it[loc*2+1];
	}
	ks(loc/2);
}
long long int calc(int loc){
	loc+=(1<<19);
	fnc res;
	res.a=0;
	res.b=0;
	res.g=0;
	res.s=0;
	while(loc>0){
		if(loc%2==0){
			if(res.g!=0)res=it[loc]+res;
			else{
				res=it[loc];
			}
			if((loc&(-loc))==loc)break;
			loc--;
		}
		loc/=2;
	}
	return res.s%mod;
}
int main(){
	int i,t,ql,qr;
	fnc xs,xt;
	fib[0]=-1;
	fib[1]=1;
	for(i=0;i<1000000;i++){
		fib[i+2]=fib[i]+fib[i+1];
		fib[i+2]%=mod;
	}
	scanf("%d%d",&n,&m);
	for(i=0;i<n+3;i++){
		if(i<n)scanf("%d",&a[i]);
		it[i+3+(1<<19)].s=a[i];
	}
	for(i=0;i<n+6;i++){
		it[i+(1<<19)].g=1;
	}
	for(i=0;i<n+6;i++){
		ks(i+(1<<19));
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&t,&ql,&qr);
		ql--;
		qr--;
		if(t==1){
			it[ql+3-1+(1<<19)].a++;
			ks(ql+3-1+(1<<19));
			it[qr+3+(1<<19)].a+=mod-fib[qr-ql+4];
			it[qr+3+(1<<19)].a%=mod;
			it[qr+3+(1<<19)].b+=mod-fib[qr-ql+3];
			it[qr+3+(1<<19)].b%=mod;
			ks(qr+3+(1<<19));
		}
		else{
			printf("%I64d\n",(calc(qr+3)+mod-(calc(ql+2)%mod))%mod);
		}
	}
}