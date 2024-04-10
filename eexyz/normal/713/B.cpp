#include<bits/stdc++.h>
using namespace std;
int ll,rr,xx,yy;
int query(int a,int b,int c,int d){
	cout<<"? "<<a<<' '<<c<<' '<<b<<' '<<d<<'\n';cout.flush();
	int x;cin>>x;
	if(ll&&a<=ll&&rr<=b&&c<=xx&&yy<=d)--x;
	return x;
}
int n,l,r,mid,L,R,X,Y;
int main(){
	cin>>n;
	l=1;r=n;
	while(l<r){
		mid=(l+r>>1);
		if(query(1,mid,1,n))r=mid;
		else l=mid+1;
	}
	R=l;
	l=1;r=R;
	while(l<r){
		mid=r-(r-l>>1);
		if(query(mid,R,1,n))l=mid;
		else r=mid-1;
	}
	L=l;
	l=1;r=n;
	while(l<r){
		mid=(l+r>>1);
		if(query(L,R,1,mid))r=mid;
		else l=mid+1;
	}
	Y=l;
	l=1;r=Y;
	while(l<r){
		mid=r-(r-l>>1);
		if(query(L,R,mid,Y))l=mid;
		else r=mid-1;
	}
	X=l;
	if(L!=R&&query(L+1,R,X,Y)){
		cout<<"???";
		l=L+1;r=R;
		while(l<r){
			mid=r-(r-l>>1);
			if(query(mid,R,X,Y))l=mid;
			else r=mid-1;
		}
		L=l;
	}
	if(L!=R&&query(L,R-1,X,Y)){
		l=L;r=R-1; 
		while(l<r){
			mid=(l+r>>1);
			if(query(1,mid,X,Y))r=mid;
			else l=mid+1;
		}
		R=l;
	}
	if(X!=Y&&query(L,R,X+1,Y)){
		while(1);
		l=X+1;r=Y;
		while(l<r){
			mid=r-(r-l>>1);
			if(query(L,R,mid,Y))l=mid;
			else r=mid-1;
		}
		X=l;
	}
	if(X!=Y&&query(L,R,X,Y-1)){
		l=X;r=Y-1;
		while(l<r){
			mid=(l+r>>1);
			if(query(L,R,X,mid))r=mid;
			else l=mid+1;
		}
		Y=l;
	}
	ll=L;rr=R;xx=X;yy=Y;
	l=1;r=n;
	while(l<r){
		mid=(l+r>>1);
		if(query(1,mid,1,n))r=mid;
		else l=mid+1;
	}
	R=l;
	l=1;r=R;
	while(l<r){
		mid=r-(r-l>>1);
		if(query(mid,R,1,n))l=mid;
		else r=mid-1;
	}
	L=l;
	l=1;r=n;
	while(l<r){
		mid=(l+r>>1);
		if(query(L,R,1,mid))r=mid;
		else l=mid+1;
	}
	Y=l;
	l=1;r=Y;
	while(l<r){
		mid=r-(r-l>>1);
		if(query(L,R,mid,Y))l=mid;
		else r=mid-1;
	}
	X=l;
	cout<<"! "<<ll<<" "<<xx<<" "<<rr<<" "<<yy<<" "<<L<<" "<<X<<" "<<R<<" "<<Y<<'\n';
}