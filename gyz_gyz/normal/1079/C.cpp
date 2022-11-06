#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define N 400000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,x,y,f[N][6];
void prt(int i,int j){
	if(i>1)prt(i-1,f[i][j]);
	printf("%d ",j);
}
int main(){
	scanf("%d%d",&n,&x);
	rep(i,2,n){
		y=x;scanf("%d",&x);
		rep(j,1,5)dep(k,5,1)
			if((((x<y)&&(j<k))||((x>y)&&(j>k))||((x==y)&&(j!=k)))&&(f[i-1][k]||i==2))f[i][j]=k;
	}
	rep(i,1,5)if(n==1||f[n][i]){
		prt(n,i);return 0;
	}
	printf("-1\n");
}