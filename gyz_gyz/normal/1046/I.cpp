#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define dec(x,y) x=(x+mo-(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 200000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,ans;ll d1,d2;bool u;
struct pr{ll x,y;}a,b,aa;
pr operator -(pr x,pr y){return {x.x-y.x,x.y-y.y};}
ll operator ^(pr x,pr y){return x.x*y.x+x.y*y.y;}
ll operator *(pr x,pr y){return abs(x.x*y.y-y.x*x.y);}
ll dis(pr x){return sqr(x.x)+sqr(x.y);} 
int main(){
	scanf("%d",&n);
	scanf("%I64d%I64d",&d1,&d2);
	rep(i,1,n){b=a;
		scanf("%I64d%I64d%I64d%I64d",&a.x,&a.y,&aa.x,&aa.y);a=a-aa;
		if((!u)&&(((a-b)^b)<0)&&(((a-b)^a)>0)){
			if(sqr(a*(a-b))<=sqr(d1)*dis(a-b))ans++,u=1;
		}
		if(!u){
			if(dis(a)<=sqr(d1))u=1,ans++;
		}else{
			if(dis(a)>sqr(d2))u=0;
		}
	}
	printf("%d",ans);
}