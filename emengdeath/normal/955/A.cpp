#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
long long hh,mm,h,d,c,n;
ld get(long long hh1,long long mm1,ld c){
	long long v=h;
	if (hh1>hh||(hh1==hh&&mm1>mm)){
		v+=((hh1-hh)*60+(mm1-mm))*d;
	}
	if (v%n)return (v/n+1)*c;
	else
		return (v/n)*c;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>hh>>mm;
	cin>>h>>d>>c>>n;
	cout<<setprecision(6)<<min(get(20,0,(ld)c/5*4),get(hh,mm,c));
	return 0;
}