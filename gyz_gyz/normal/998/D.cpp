#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define gc getchar()
#define N 1000000
#define ll long long
#define inf 1000000000
#define mo 1000000007
#define eps 1e-6
using namespace std;
int n,a1,a2,a3,a4,p;ll ans;
void tr(ll x){
	a1=x/50;x%=50;a2=x/10;x%=10;
	a3=x/5;a4=x%5;p=n-a1-a2-a3-a4;
	if(p<0)return;
	if(a1>=p/4){
		a1-=p/4;a2+=p/4*5;p%=4;
	}else{
		a2+=a1*5;p-=a1*4;a1=0;
	}
	if(a2>=p){
		a3+=p*2;a2-=p;p=0;
	}else if(a2>5){
		a3+=(a2-5)*2;p-=a2-5;a2=5;
	}
	while(p){
		if(a3>=p/4){
			a3-=p/4;a4+=p/4*5;p%=4;
		}else{
			a4+=a3*5;p-=a3*4;a3=0;
		}
		if((!a2)||(!p))break;
		a2--;a3+=2;p--;
	}
	if(!p)ans++;
}
int main(){
	scanf("%d",&n);
	if(n<5000)rep(i,n,n*50)tr(i);else{
		ans=(n*50ll-1000)-(n+1000);
		rep(i,0,1000)tr(n+i);
		rep(i,0,999)tr(n*50ll-i);
	}
	printf("%I64d\n",ans);
}