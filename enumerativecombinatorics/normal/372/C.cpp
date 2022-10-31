#include<stdio.h>
#include<algorithm>
#include<deque>
using namespace std;
long long dp[2][150010];
int p[310];
int r[310];
int ABS(int a){return max(a,-a);}
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	long long ret=0LL;
	for(int i=0;i<b;i++){
		int q;scanf("%d%d%d",p+i+1,&q,r+i+1);
		p[i+1]--;
		ret+=q;
	}
	for(int i=0;i<a;i++)dp[0][i]=0LL;
	for(int i=1;i<=b;i++){
		int B=i&1;
		int m=(int)min((long long)a,(long long)(r[i]-r[i-1])*c);
		deque<int> Q;
		for(int j=0;j<a+m;j++){
			if(j<a){
				while(Q.size()&&dp[!B][Q.back()]>=dp[!B][j])Q.pop_back();
				Q.push_back(j);
			}
			if(j>=m){
				dp[B][j-m]=dp[!B][Q.front()]+ABS(p[i]-(j-m));
			}
			if(j>=2*m){
				if(Q.front()==j-2*m)Q.pop_front();
			}
		}
	}
	long long v=9999999999999999LL;
	for(int i=0;i<a;i++)v=min(v,dp[b&1][i]);
	printf("%I64d\n",ret-v);
}