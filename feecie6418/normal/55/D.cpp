#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long f[20][55][2600],c[20];
long long l[5005],tot=0;
void Turn(long long k) {
	memset(c,0,sizeof(c));
	while(k)c[++c[0]]=k%10,k/=10;
	return ;
}
int gcd(int x,int y){
	return x%y?gcd(y,x%y):y;
}
long long Search(int x,int lcm,int num,bool flag) {
	if(!x&&num%lcm==0)return 1;
	else if(!x)return 0;
	if(!flag&&~f[x][l[lcm]][num])return f[x][l[lcm]][num];
	int k=flag?c[x]:9;
	long long s=0;
	for(int i=0; i<=k; i++) {
		s+=Search(x-1,i?lcm*i/gcd(lcm,i):lcm,(num*10+i)%2520,flag&&i==k);
	}
	if(!flag)f[x][l[lcm]][num]=s;
	return s;
}
long long Calc(long long k) {
	Turn(k);
	return Search(c[0],1,0,1);
}
int main() {
	for(int i=1; i<=2520; i++)if(2520%i==0)l[i]=++tot;
	memset(f,-1,sizeof(f));
	long long x,y;
	int T;
	cin>>T;
	while(T--) {
		cin>>x>>y;
		cout<<Calc(y)-Calc(x-1)<<endl;
	}
	return 0;
}