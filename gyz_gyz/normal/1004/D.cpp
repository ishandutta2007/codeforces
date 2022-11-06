#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define abs(x) ((x)<0?-(x):(x))
#define N 1048576
#define ll long long
#define inf 1000000000
using namespace std;
int n,x,fs,ls,a[N],b[N];
void f(int n,int m,int x,int y){
	if((x>n)||(y>m)||(x<1)||(y<1))return;
	rep(i,1,n*m)b[i]=0;
	rep(i,1,n)rep(j,1,m)b[abs(i-x)+abs(j-y)]++;
	rep(i,1,n*m)if(b[i]!=a[i])return;
	printf("%d %d\n%d %d\n",n,m,x,y);exit(0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){scanf("%d",&x);a[x]++;}
	rep(i,1,n)if(a[i]-a[i-1]+(i==1)<4){fs=i;break;}
	rep(i,1,n)if(!a[i]){ls=i-1;break;}
	rep(i,1,n){
		if(i*i>n)break;
		if(!(n%i)){
			f(i,n/i,fs,ls-i+fs+1);
			f(i,n/i,ls-n/i+fs+1,fs);
		}
	}
	printf("-1");
}