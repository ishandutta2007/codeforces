#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL g[8999999+10];int x,y,z;int n,m,a,b;
LL mat[3001][3001];
LL st_algor[3001][13];//<- reuse guy
LL dp[3001][3001];
LL res=0;
void calc(){
	int ci2=int(log2(double(b)));
	rb(i,1,n-a+1){
		rb(j,1,m) st_algor[j][0]=dp[i][j];
		rb(k,1,12){
			rb(j,1,m){
				if(j+(1<<k)-1>m) break;
				st_algor[j][k]=min(st_algor[j][k-1],st_algor[j+(1<<(k-1))][k-1]);
			}
		}
		rb(j,1,m-b+1){
			res+=min(st_algor[j][ci2],st_algor[j+b-(1<<(ci2))][ci2]);
		}
	}
}
int main(){
	scanf("%d %d %d %d",&n,&m,&a,&b);
	scanf("%I64d %d %d %d",&g[0],&x,&y,&z);
	rb(i,1,8999999){
		g[i]=g[i-1]*x;
		g[i]+=y;
		g[i]%=z;
	}
	rb(i,1,n){
		rb(j,1,m){
			mat[i][j]=g[(i-1)*m+j-1];
		}
	}
	int ci=int(log2(double(a)));
	rb(j,1,m){
		rb(i,1,n) st_algor[i][0]=mat[i][j];
		rb(k,1,12){
			rb(i,1,n){
				if((i+(1<<k))-1>n) break;
				st_algor[i][k]=min(st_algor[i][k-1],st_algor[i+(1<<(k-1))][k-1]);
			}
		}
		rb(i,1,n-a+1){
			dp[i][j]=min(st_algor[i][ci],st_algor[i+a-(1<<ci)][ci]);
		}
	}
	calc();
	printf("%I64d\n",res);
	return 0;
}