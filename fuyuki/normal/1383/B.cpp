#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=2e5+100,INF=0x3f3f3f3f;
int T,n,a[N],cnt[31];
void work(){
	FOR(j,0,30)cnt[j]=0;
	scanf("%d",&n);
	FOR(i,1,n)scanf("%d",a+i);
	FOR(i,1,n)FOR(j,0,30)cnt[j]+=a[i]>>j&1;
	ROF(i,30,0)if(cnt[i]&1){
		int one=cnt[i]+1>>1;
		if(one%2==1||n%2==0)return void(cout<<"WIN\n");
		else return void(cout<<"LOSE\n");
	}
	cout<<"DRAW\n";
}
int main(){
	for(scanf("%d",&T);T--;)work();
	return 0;
}