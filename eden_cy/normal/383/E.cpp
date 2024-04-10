#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 10005
#define N 24

typedef long long ll;

char str[M][3];
bool judge(int x,int y) {
	FOR(i,0,2) if(str[y][i]==(char)'a'+x) return true;
	return false;
}
int sum1[1<<N];
int sum2[1<<N];
int sum3[1<<N];
int main() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%s",str[i]);
	FOR(i,0,23) FOR(j,1,n) sum1[1<<i]+=judge(i,j);
	FOR(i,0,23) FOR(j,i+1,23) FOR(k,1,n) sum2[(1<<i)|(1<<j)]+=judge(i,k)&&judge(j,k);
	FOR(i,0,23) FOR(j,i+1,23) FOR(k,j+1,23) FOR(h,1,n) sum3[(1<<i)|(1<<j)|(1<<k)]+=judge(i,h)&&judge(j,h)&&judge(k,h);
	ll res=0;
//	FOR(i,1,(1<<24)-1) cnt[i]=cnt[i^(i&-i)]+1;
//	int tmp=0;
	FOR(i,0,(1<<24)-1) {
		int x=i,j,cnt=0;
		while(x) {
			cnt++;
			j=x&-x;
			sum1[i]+=sum1[i^j];
			sum2[i]+=sum2[i^j];
			sum3[i]+=sum3[i^j];
			x^=j;
		}
		if(cnt>1) sum1[i]/=cnt-1;
		if(cnt>2) sum2[i]/=cnt-2;
		if(cnt>3) sum3[i]/=cnt-3;
//		if(i<=20)printf("i=%d sum=%d\n",i,sum1[i]-sum2[i]+sum3[i]);
//		if(sum1[i]-sum2[i]+sum3[i]!=n) cerr<<sum1[i]-sum2[i]+sum3[i]<<endl;
		res^=1ll*(sum1[i]-sum2[i]+sum3[i])*(sum1[i]-sum2[i]+sum3[i]);
	}
//	printf("%d\n",tmp);
	printf("%lld\n",res);
	return 0;
}