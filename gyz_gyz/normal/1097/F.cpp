#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 100010
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
const int m=7000;
bitset<m+1>a[N],b[N],mu;int n,q;
int main(){
	scanf("%d%d",&n,&q);mu.set();
	rep(i,2,m)rep(j,1,m/i/i)mu[i*i*j]=0;
	rep(i,1,m)rep(j,1,m/i)b[i][i*j]=mu[j];
	rep(i,1,q){int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){a[x].reset();
			rep(j,1,y){
				if(j*j>y)break;
				if(!(y%j))a[x][j]=a[x][y/j]=1;
			}
		}else if(op==4){
			printf("%d",(a[x]&b[y]).count()&1);
		}else{
			int z;scanf("%d",&z);
			if(op==2)a[x]=a[y]^a[z];else a[x]=a[y]&a[z];
		}
	}
}