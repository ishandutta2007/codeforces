#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 33
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,Q;
ll a[N][N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=(i&1?0:1LL<<(i+j-2));
			printf("%I64d ",a[i][j]);
		}
		printf("\n");
	}
	fflush(stdout);
	Q=read();
	while(Q--){
		ll x=read();
		int nx=1,ny=1;
		printf("%d %d\n",nx,ny);
		for(int i=1;i<=(n<<1)-2;++i){
			if((nx==n||a[nx+1][ny]^(x&(1LL<<i)))&&ny<n){
				++ny;
			}
			else{
				++nx;
			}
			printf("%d %d\n",nx,ny);
		}
		fflush(stdout);
	}
	return 0;
}