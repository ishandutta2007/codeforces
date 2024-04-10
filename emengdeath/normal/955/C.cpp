#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll L,R;
int bz[68];
ll d[68][1000];
int check(int x){
	int sig=-1;
	for (int i=2;i*i<=x;i++){
		if (!(x%i)){
			sig*=-1;
			x/=i;
			if (!(x%i))return 0;
		}
	}
	if (x!=1)sig*=-1;
	return sig;
}
ll check(ll x,int y,ll z){
	while (z/x)z/=x,y--;
	return y<=0;
}
ll did(int x){
	ll s=1;
	while (x--)s*=10;
	return s;
}
ll er(ll x,int y){
	if (y>=10){
		int l=1,r=d[y][0],mid,s=0;
		while (l<=r){
			if (d[y][mid=(l+r)/2]<=x)s=max(s,mid),l=mid+1;
			else
				r=mid-1;
		}
		return s;
	}else{
		ll l=2,r=did(18/y+1),mid,s=0;
		while (l<=r){
			if (check(mid=(l+r)/2,y,x))s=max(s,mid),l=mid+1;
			else
				r=mid-1;
		}
		return max(s-1,(ll)0);
	}
}
ll get(ll x){
	ll s=0;
	for (int i=2;i<=68;i++)
		if (bz[i])
			s+=bz[i]*er(x,i);
	return s;
}
ll calc(ll x,ll y){
	ll s=1;
	while (y){
		if (y&1)s*=x;
		x*=x,y/=2;
	}
	return s;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>q;
	for (int i=2;i<68;i++){
		bz[i]=check(i);
		if (i>=10&&bz[i]){
			for (int j=2;;j++)
				if (check(j,i,1e18)){
					d[i][++d[i][0]]=calc(j,i);
				}else
					break;
		}
	}
	while (q--){
		cin>>L>>R;
		if (L==1)
			cout<<get(R)-get(L-1)+1<<endl;
		else
			cout<<get(R)-get(L-1)<<endl;
	}
	return 0;
}