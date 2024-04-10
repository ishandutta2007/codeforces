#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct xian{ll x,y,z,p;}a[1010];
struct Po{ll x,y;}b[1000010];
ll n,x,y,nb,ansn;
void get(ll p0_x,ll p0_y,ll p1_x,ll p1_y,ll p2_x,ll p2_y,ll p3_x,ll p3_y){
    ll s02_x,s02_y,s10_x,s10_y,s32_x,s32_y,s_numer,t_numer,denom,t;
    s10_x=p1_x-p0_x;
    s10_y=p1_y-p0_y;
    s32_x=p3_x-p2_x;
    s32_y=p3_y-p2_y;
    denom=s10_x*s32_y-s32_x*s10_y;
    if(denom==0)return ;
    bool denomPositive=denom>0;
    s02_x=p0_x-p2_x;
    s02_y=p0_y-p2_y;
    s_numer=s10_x*s02_y-s10_y*s02_x;
    if((s_numer<0)==denomPositive&&s_numer!=0)return ;
    t_numer=s32_x*s02_y-s32_y*s02_x;
    if((t_numer<0)==denomPositive&&t_numer!=0)return ;
    if(((s_numer>denom)==denomPositive&&s_numer!=denom)||((t_numer>denom)==denomPositive&&t_numer!=denom))return ;
    if (t_numer*s10_x%denom!=0) return ;
    if (t_numer*s10_y%denom!=0) return ;
    b[++nb].x=t_numer*s10_x/denom+p0_x;
    b[nb].y=t_numer*s10_y/denom+p0_y;
    return ;
}
bool comp(const Po &a,const Po &b){if (a.x!=b.x)return a.x<b.x;return a.y<b.y;}
int co(int x){
	int sum=0,sum1=1;
	while (1){
		sum+=sum1;
		if (x==sum) return sum1;
		sum1++;
	}
}
ll gcd(ll x,ll y){if (y==0) return x;if (x%y==0) return y;return gcd(y,x%y);}
ll co(ll x,ll y,ll z,ll p){
	return gcd(abs(z-x),abs(p-y))+1;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z>>a[i].p;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			get(a[i].x,a[i].y,a[i].z,a[i].p,a[j].x,a[j].y,a[j].z,a[j].p);
	sort(b+1,b+nb+1,comp);
	for (int i=1,j=1;i<=nb;i=j+1){
		while ((b[j+1].x==b[i].x)&&(b[j+1].y==b[i].y)&&j<nb) j++;
		ansn-=co(j-i+1);
	}
	for (ll i=1;i<=n;i++) ansn+=co(a[i].x,a[i].y,a[i].z,a[i].p);
	cout<<ansn<<endl;
	return 0;
}
/*
3
0 0 2 2
0 2 2 0
0 1 2 1
0 -1 2 3
*/