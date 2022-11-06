
 #include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
ll l,r,mx,a[6][N],q[N];int x;
int main(){
	l=1;r=10004205361450474ll;
	rep(i,1,10000)a[1][i]=i*2-1;
	rep(i,2,5)rep(j,1,10000){a[i][j]=j-1;
		rep(k,0,j){
			if(a[i][j]>=10000){
				a[i][j]+=(a[i-1][10000]-9998)*(j-k+1);break;
			}
			a[i][j]=a[i-1][a[i][j]+1]+1;
		}a[i][j]--;
	}
	dep(i,5,2){
		q[0]=l-1;mx=min(l,10000ll);
		rep(j,1,mx)if(q[j-1]+1<10000)q[j]=a[i-1][q[j-1]+1]+1;
		else q[j]=q[j-1]+a[i-1][10000]-9998;
		printf("%I64d",mx);
		rep(j,1,mx)printf(" %I64d",q[j]);printf("\n");
		fflush(stdout);scanf("%d",&x);
		if(x==-1)return 0;
		if(x<mx)r=q[x+1]-1;l=q[x]+1;
	}
	printf("%I64d",r-l+1);
	rep(i,0,r-l)printf(" %I64d",l+i);printf("\n");
}