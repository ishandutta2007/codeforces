#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;

struct Rec{
	ll x1,y1,x2,y2;
}ans1,ans2;

inline int query1(ll x1,ll y1,ll x2,ll y2){
	printf("? %lld %lld %lld %lld\n",x1,y1,x2,y2);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

inline int query2(ll x1,ll y1,ll x2,ll y2){
	printf("? %lld %lld %lld %lld\n",x1,y1,x2,y2);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	if(x1<=ans1.x1&&ans1.x2<=x2&&y1<=ans1.y1&&ans1.y2<=y2)res--;
	return res;
}

int main(){
	scanf("%d",&n);
	ll l,r;
	l=1;r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(query1(1,mid+1,n,n)==2)l=mid+1;
		else r=mid;
	}
	r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(query1(1,mid+1,n,n))l=mid+1;
		else r=mid;
	}
	ll at1,at2,at3,at4;
	at1=l;
	r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(query1(1,at1,n,mid))r=mid;
		else l=mid+1;
	}
	at2=r;
	l=1,r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(query1(mid+1,at1,n,at2))l=mid+1;
		else r=mid;
	}
	at3=l;
	r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(query1(at3,at1,mid,at2))r=mid;
		else l=mid+1;
	}
	at4=r;
	ans1=(Rec){at3,at1,at4,at2};

	l=1;r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(query2(1,mid+1,n,n))l=mid+1;
		else r=mid;
	}
	at1=l;
	r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(query2(1,at1,n,mid))r=mid;
		else l=mid+1;
	}
	at2=r;
	l=1;r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(query2(mid+1,at1,n,at2))l=mid+1;
		else r=mid;
	}
	at3=l;
	r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(query2(at3,at1,mid,at2))r=mid;
		else l=mid+1;
	}
	at4=r;
	ans2=(Rec){at3,at1,at4,at2};

	printf("! %lld %lld %lld %lld %lld %lld %lld %lld\n",ans1.x1,ans1.y1,ans1.x2,ans1.y2,ans2.x1,ans2.y1,ans2.x2,ans2.y2);
	fflush(stdout);
	return 0;
}