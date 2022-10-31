#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;

int segtree[2048][11000];
void buildRMQ(int *a, int n,int to) {
  int logn = 1;
  for (int k = 1; k < n; k *= 2) ++logn;
  int *r = new int[n * logn];
  int *b = r; copy(a, a+n, b);
  for (int k = 1; k < n; k *= 2) {
    copy(b, b+n, b+n); b += n;
    for(int i=0;i< n-k;i++) b[i] = min(b[i], b[i+k]);
  }
for(int j=0;j<n*logn;j++)segtree[to][j]=r[j];
}
int minimum(int x, int y, int *rmq, int n) {
  int z = y - x, k = 0, e = 1, s; // y - x >= e = 2^k  k
  s = ( (z & 0xffff0000) != 0 ) << 4; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000ff00) != 0 ) << 3; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x000000f0) != 0 ) << 2; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x0000000c) != 0 ) << 1; z >>= s; e <<= s; k |= s;
  s = ( (z & 0x00000002) != 0 ) << 0; z >>= s; e <<= s; k |= s;
  return min( rmq[x+n*k], rmq[y+n*k-e+1] );
}
int dp[1010][1010];
int f[2048][1100];
int c[1010][1010];
int L,R;
int m;
int query(int a,int b,int c,int d,int e){
	if(d<a||b<c)return 0;
	if(c<=a&&b<=d){
	//	printf("%d %d %d %d\n",a,b,L,R);fflush(stdout);
		int ret=minimum(L,R,segtree[e],m);
		return ret;
	}
	return min(query(a,(a+b)/2,c,d,e*2),query((a+b)/2+1,b,c,d,e*2+1));
}
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	m=b;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++)scanf("%d",&c[i][j]);
	}
	for(int i=0;i<a;i++)for(int j=0;j<b;j++){
		if(!c[i][j])continue;
		int tmp=mod;
		if(i==0||j==0)tmp=0;
		else tmp=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
		dp[i][j]=tmp+1;
	}

	for(int i=0;i<a;i++)for(int j=0;j<b;j++)
		f[i+1024][j]=-dp[i][j];
	for(int i=2047;i>0;i--){
		for(int j=0;j<b;j++){
			f[i/2][j]=min(f[i/2][j],f[i][j]);
		}
		buildRMQ(f[i],b,i);
	//	segtree[i]=buildRMQ(f[i],b);
	}
	int T;scanf("%d",&T);
	while(T--){
		int p,q,r,s;
		scanf("%d%d%d%d",&p,&q,&r,&s);
		p--;q--;r--;s--;
		int left=0;
		int right=min(r-p+1,s-q+1)+1;
		while(left+1<right){
			int M=(left+right)/2;
			int t1=p+M-1;
			int t2=q+M-1;
			R=s;L=t2;
			//printf("%d %d\n",l,r);
			if(query(0,1023,t1,r,1)<=-M){
				left=M;
			}else{
				right=M;
			}
		}
		printf("%d\n",left);
	}
}