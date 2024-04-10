#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
LL a[10];
LL cal(int x,LL w){
	if(x==1)
	return min(w,a[x]); 
	LL num=min(a[x],w/x);
	LL res=0;
	for(int i=0;i<8&&i<=num;i++){
		res=max(res,cal(x-1,w-(num-i)*x)+(num-i)*x);
	}
	//printf("%d %lld %d\n",x,w,res);
	return res;
}
int main(){
	LL w;
	scanf("%lld",&w);
	for(int i=1;i<=8;i++)
	scanf("%lld",&a[i]);
	printf("%lld\n",cal(8,w));
}