#include<bits/stdc++.h>
using namespace std;
#define N 150005
int n,i,t[N],cc,ps[N],j,ans;
inline int check(int ps){
	if(ps<=0||ps>n)return 1;
	if(ps==1)return t[1]<t[2];
	if(ps&1)return t[ps]<t[ps-1];
	return t[ps]>t[ps-1];
}
inline int check(int l,int r){
	swap(t[l],t[r]);
	for(int i=1;i<=cc;++i){
		if(!check(ps[i]-1))return 0;
		if(!check(ps[i]))return 0;
		if(!check(ps[i]+1))return 0;
		if(!check(ps[i]+2))return 0;
	}
	if(!check(l))return 0;
	if(!check(l-1))return 0;
	if(!check(l+1))return 0;
	if(!check(r))return 0;
	if(!check(r-1))return 0;
	if(!check(r+1))return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;++i)cin>>t[i];
	for(i=1;i<=n;i+=2){
		if(((i+1<=n&&t[i]>=t[i+1])||(t[i]>=t[i-1]&&i>1))){
			ps[++cc]=i;
		}
	}
	if(cc>=4){
		return cout<<0,0;
	}
	for(i=1;i<=n;++i){
		for(j=max(ps[1]-1,1);j<=ps[1]+1&&j<=n;++j){
			if((i>ps[1]+1||i<ps[1]-1||i<j)){
				if(check(i,j))++ans;
				swap(t[i],t[j]);
			}
		}
	}
	cout<<ans;
}