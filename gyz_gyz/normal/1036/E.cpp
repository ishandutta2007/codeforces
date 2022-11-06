#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
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
#define N 400000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
struct pr{ll x,y;};
bool operator <(pr x,pr y){
	if(x.x==y.x)return x.y<y.y;else return x.x<y.x;
}
int n;ll x1[N],y1[N],x2[N],y2[N],ans,a1,b1,c1,a2,b2,c2,s0,s1,s2,x,y;set<pr>s;
ll gcd(ll x,ll y){
	if(!x)return y;
	if(!y)return x;
	return gcd(y%x,x);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%I64d%I64d%I64d%I64d",&x1[i],&y1[i],&x2[i],&y2[i]);
		a1=y1[i]-y2[i];b1=x2[i]-x1[i];c1=x1[i]*y2[i]-x2[i]*y1[i];
		ans+=gcd(abs(x1[i]-x2[i]),abs(y1[i]-y2[i]))+1;s.clear();
		rep(j,1,i-1){
			a2=y1[j]-y2[j];b2=x2[j]-x1[j];c2=x1[j]*y2[j]-x2[j]*y1[j];
			s0=a2*b1-a1*b2;s1=c1*b2-c2*b1;s2=a2*c1-a1*c2;
			if(s0&&(!(abs(s1)%abs(s0)))&&(!(abs(s2)%abs(s0)))){
				x=s1/s0;y=-s2/s0;
				if((x>=min(x1[i],x2[i]))&&(x<=max(x1[i],x2[i]))
				&&(x>=min(x1[j],x2[j]))&&(x<=max(x1[j],x2[j]))
				&&(y>=min(y1[i],y2[i]))&&(y<=max(y1[i],y2[i]))
				&&(y>=min(y1[j],y2[j]))&&(y<=max(y1[j],y2[j])))s.insert({x,y});
			}
		}ans-=s.size();
	}
	printf("%I64d",ans);
}