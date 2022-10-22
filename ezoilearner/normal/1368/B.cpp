#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll K;

int a[100];
char c[100];

int main(){
	scanf("%lld",&K);
	ll sum=0;
	int at=1;
	c[1]='c';c[2]='o';c[3]='d';c[4]='e';c[5]='f';c[6]='o';c[7]='r';c[8]='c';c[9]='e';c[10]='s';
	while(sum<K){
		a[at]++;
		if(at==10)at=1;
		else at++;
		sum=1;
		for(int i=1;i<=10;++i)sum*=a[i];
	}
	for(int i=1;i<=10;++i)
	    for(int j=1;j<=a[i];++j)printf("%c",c[i]);
	puts("");
	return 0;
}