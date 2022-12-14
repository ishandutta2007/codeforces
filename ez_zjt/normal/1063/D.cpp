#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL n,l,r,s,n1,n2;

bool check1(LL t,LL s,LL flag){
	LL temp=s/(t+n);
	LL temp2=s%(t+n);
	if(temp2>=n1+flag && temp2<=n1+min(t,n1) && t-(temp2-n1)>=0 && t-(temp2-n1)<=n2) return 1;
	if(temp){
		temp2+=t+n;
		if(temp2>=n1+flag && temp2<=n1+min(t,n1) && t-(temp2-n1)>=0 && t-(temp2-n1)<=n2) return 1;
	}
	return 0;
}

bool check1(LL t){
	return check1(t,s,0) || check1(t,s+1,1);
}

LL solve1(){
	for(LL x=n;x>=0;x--)
		if(check1(x)) 
			return x;
	return -1;
}

LL div1(LL x,LL y){
	if(!x) return 0;
	if(x>0) return x/y;
	else{
		x=-x;
		return -((x-1)/y+1);
	}
}

LL div2(LL x,LL y){
	if(!x) return 0;
	if(x>0) return (x-1)/y+1;
	else{
		x=-x;
		return -(x/y);
	}
}

LL calc2(LL k,LL s,LL flag){
	s-=k*n+n1;
	LL l1=div2(s,k+1);
	LL l2=div2(s-n1,k);
	LL l3=div1(s-flag,k);
	LL l4=div1(s+n2,k+1);
	l1=max(l1,l2);
	l3=min(l3,l4);
	if(l1<=l3) return l3;
	return -1;
}

LL solve2(){
	LL ans=-1;
	if(s>=n1 && s<=n1*2){
		ans=max(ans,s-n1+n2);
	}
	if(s+1>n1 && s+1<=n1*2){
		ans=max(ans,s+1-n1+n2);
	}
	for(LL k=1;k*n<=s+1;k++){
		ans=max(ans,calc2(k,s,0));
		ans=max(ans,calc2(k,s+1,1));
	}
	return ans;
}

int main(){
	cin>>n>>l>>r>>s;
	n1=r-l+1;
	if(n1<=0) n1+=n;
	n2=n-n1;
	if(n<s/n) cout<<solve1()<<endl;
	else cout<<solve2()<<endl;
	return 0;
}