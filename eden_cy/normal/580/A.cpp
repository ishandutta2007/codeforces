#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 100005

int Num[M];
int main() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&Num[i]);
	int res=0,tmp=1;
	FOR(i,2,n) {
		if(Num[i]>=Num[i-1]) tmp++;
		else {
			if(tmp>res) res=tmp;
			tmp=1;
		}
	}
	if(tmp>res) res=tmp;
	printf("%d\n",res);
	return 0;	
}