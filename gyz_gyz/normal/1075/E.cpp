#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define ll long long
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n;struct pr{int x,y;}u,d,l,r,ul,ur,dl,dr;
int main(){
	scanf("%d%d%d",&n,&u.x,&u.y);ul=ur=dl=dr=d=l=r=u;
	rep(i,2,n){pr x;
		scanf("%d%d",&x.x,&x.y);
		if(x.x<u.x)u=x;
		if(x.x>d.x)d=x;
		if(x.y<l.y)l=x;
		if(x.y>r.y)r=x;
		if(x.x+x.y<ul.x+ul.y)ul=x;
		if(x.x+x.y>dr.x+dr.y)dr=x;
		if(x.x-x.y<ur.x-ur.y)ur=x;
		if(x.x-x.y>dl.x-dl.y)dl=x;
	}
	printf("%d",max(max(d.x+r.y-ul.x-ul.y,d.x-l.y-ur.x+ur.y),
	max(dl.x-dl.y-u.x+r.y,dr.x+dr.y-u.x-l.y))*2);
	rep(i,4,n)printf(" %d",(d.x-u.x+r.y-l.y)*2);
}