/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
mp point[300000+20];
bool check(int mid){
	//find such point (x,y)-> |x-xi|<=m,|y-yi|<=m,|(x-y)-(xi-yi)|<=m
	int lx,ly,rx,ry;
	lx=ly=-INF;
	rx=ry=INF;
	rb(i,1,n)
	{
		int l,r;
		l=point[i].FIR-mid;
		r=point[i].FIR+mid;
		lx=max(lx,l);
		rx=min(rx,r);
		l=point[i].SEC-mid;
		r=point[i].SEC+mid;
		ly=max(ly,l);
		ry=min(ry,r);
	}
	if(lx>rx||ly>ry) return 0;
	int l,r;
	if(rx<ly){
		r=rx-ly;
		l=lx-ry;
	}
	if(lx>ry){
		r=rx-ly;
		l=lx-ry;
	}
	else{
		r=rx-ly;
		l=lx-ry;
	}
	int  ll,rr;
	ll=INF;
	rr=-INF; 
	rb(i,1,n){
		int tmp=point[i].FIR-point[i].SEC;
		ll=min(ll,tmp);
		rr=max(rr,tmp);
	}
	int best_mid=ll+mid;
	best_mid=min(best_mid,r);
	if(best_mid<l||best_mid+mid<rr) return 0;
	return 1;
}
void  recover(int mid){
	//this function almost copies from "check"
	int lx,ly,rx,ry;
	lx=ly=-INF;
	rx=ry=INF;
	rb(i,1,n)
	{
		int l,r;
		l=point[i].FIR-mid;
		r=point[i].FIR+mid;
		lx=max(lx,l);
		rx=min(rx,r);
		l=point[i].SEC-mid;
		r=point[i].SEC+mid;
		ly=max(ly,l);
		ry=min(ry,r);
	}
	int l,r;
		if(rx<ly){
		r=rx-ly;
		l=lx-ry;
	}
	if(lx>ry){
		r=rx-ly;
		l=lx-ry;
	}
	else{
		r=rx-ly;
		l=0;
	}
	int  ll,rr;
	ll=INF;
	rr=-INF; 
	rb(i,1,n){
		int tmp=(point[i].FIR-point[i].SEC);
		ll=min(ll,tmp);
		rr=max(rr,tmp);
	}
	int best_mid=ll+mid;
	best_mid=min(best_mid,r);
	rb(i,lx,rx){
		int can_y;
		can_y=i-best_mid;
		if(can_y>0||i>0)
		if(can_y>=0&&can_y>=ly&&can_y<=ry){
			rb(j,1,i)
			{
				cout<<"N";	
			}
			rb(j,1,can_y)
			{
				cout<<"B";
			}
			return;
		}
	}
} 
int main(){
	fastio;
	R(n);
	rb(i,1,n){
		string s;
		R(s);
		int x,y;
		x=y=0;
		rep(j,s.length()){
			if(s[j]=='N'){
				x++;
			}
			else{
				y++;
			}
		}
		point[i]=II(x,y);
	}
	int l=0,r=INF;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<l<<endl;
	recover(l);
	return 0;
}