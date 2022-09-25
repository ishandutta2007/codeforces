#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> poly;
int n,m;
string s[20];
void FWT(poly &f,int opt,int n){
	for(int j=0;j<n;++j){
		for(int i=0;i<1<<n;++i){
			if(!(i>>j&1)){
				ll t1=f[i],t2=f[i|(1<<j)];
				if(opt==1){
					f[i]=t1+t2,f[i|(1<<j)]=t1-t2;
				}
				else{
					f[i]=(t1+t2)/2,f[i|(1<<j)]=(t1-t2)/2;
				}
			}
		}
	}
}
poly Mul(poly A,poly B){
	poly C(A.size());
	FWT(A,1,n),FWT(B,1,n);
	for(int i=0;i<(int)A.size();++i){
		C[i]=A[i]*B[i];
	}
	FWT(C,-1,n);
	return C;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>s[i];
	}
	poly A(1<<n),B(1<<n);
	for(int j=0;j<m;++j){
		int z=0;
		for(int i=0;i<n;++i){
			if(s[i][j]=='1')z|=1<<i;
		}
		++A[z];
	}
	for(int i=0;i<1<<n;++i){
		int cnt=__builtin_popcount(i);
		B[i]=min(cnt,n-cnt);
	}
	A=Mul(A,B);
	cout<<(*min_element(A.begin(),A.end()))<<'\n';
	return 0;
}