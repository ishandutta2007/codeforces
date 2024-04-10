#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 1005

typedef long double db;

int cnt[M];
db C(int n,int m){
	if(n<m) return 0;
	db tmp=1;
	FOR(i,n-m+1,n) tmp*=i,tmp/=n-i+1;
	return tmp;
}
int main() {
	int n,m,h;
	scanf("%d%d%d",&n,&m,&h);
	int tot=0;
	FOR(i,1,m) scanf("%d",&cnt[i]);
	FOR(i,1,m) tot+=cnt[i];
	if(tot<n) {
		puts("-1");
		return 0;
	}
	n--;tot-=cnt[h]--;
	db res=0;
	db tmp=C(tot+cnt[h],n);
	FOR(i,1,min(n,cnt[h])){
		res+=C(cnt[h],i)/tmp*C(tot,n-i);
	}
	printf("%.8Lf\n",res);
	return 0;
}