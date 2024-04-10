#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define N 100010
typedef long long ll;
inline int read(){
    int x=0,f=1;
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
int n;
long double emm,ans,pw2[2333];
struct Point{
	ll x,y;
	Point(ll _x=0,ll _y=0){x=_x,y=_y;}
	inline ll operator %(const Point b){
		return x*b.y-y*b.x;
	}
}p[N];
typedef vector<Point> Poly;
Poly qwq;
ll Abs(ll x){
	return x>=0?x:-x;
}
inline ll _gcd(ll a,ll b){
	if(b==0)return Abs(a);
	return _gcd(b,a%b);
}
void check1(Poly &p){
	for(register int i=0;i<n;++i){
		ll tot=0,bord=0;
		for(int j=0;j<min(50,n-1);++j){
			tot+=p[(i+j)%n]%p[(i+j+1)%n];
			bord+=_gcd(p[(i+j)%n].x-p[(i+j+1)%n].x,p[(i+j)%n].y-p[(i+j+1)%n].y);
			if(j>0){
				ll S=tot+p[(i+j+1)%n]%p[i],B=bord+_gcd(p[(i+j+1)%n].x-p[i].x,p[(i+j+1)%n].y-p[i].y);
				if(n<=500)ans+=(pw2[n-(j+2)]-1)/emm*(((S+2)-B)/2+_gcd(p[(i+j+1)%n].x-p[i].x,p[(i+j+1)%n].y-p[i].y)-1);
				else ans+=1.0/pw2[(j+2)]*(((S+2)-B)/2+_gcd(p[(i+j+1)%n].x-p[i].x,p[(i+j+1)%n].y-p[i].y)-1);
			}
		}
	}
	ll sumS=0,sumB=0;
	for(int i=0;i<n;++i){
		sumS+=p[i]%p[(i+1)%n];
		sumB+=_gcd(p[i%n].x-p[(i+1)%n].x,p[i%n].y-p[(i+1)%n].y);
	}
	ans=((sumS+2)-sumB)/2-ans;
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	n=read();
	if(n<=500){
		emm=pow(2.0L,n)-1-n-n*(n-1)/2;
	}
	pw2[0]=1.0;
	for(int i=1;i<=1000;++i){
		pw2[i]=pw2[i-1]*2.0;
	}
	emm=pow(2.0L,n)-1-n-n*(n-1)/2;
	for(int i=1;i<=n;++i){
		ll x=read(),y=read();
		qwq.push_back(Point(x,y));
	}
	check1(qwq);
	double tmp=ans;
	printf("%.10lf\n",tmp);
	return 0;
}