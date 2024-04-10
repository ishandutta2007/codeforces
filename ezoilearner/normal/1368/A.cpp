#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int a,b,n;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&n);
		if(a>b)swap(a,b);
		int res=0;
		while(b<=n){
			res++;
			a+=b;
			swap(a,b);
		}
		printf("%d\n",res);
	}
	return 0;
}