#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string a,b;
vector<ll> A,B;
void FWT_or(vector<ll> &f,int x,int n){
	for(int p=2;p<=n;p<<=1){
		int len=p>>1;
		for(int k=0;k<n;k+=p){
			for(int i=k;i<k+len;++i){
				f[i+len]+=x*f[i];	
			}		
		}
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>a>>b;
	A.resize(1<<n);
	B.resize(1<<n);
	for(int i=0;i<(1<<n);++i){
		A[i]=(ll)(a[i]-'0')<<(__builtin_popcount(i)<<1);
		B[i]=(ll)(b[i]-'0')<<(__builtin_popcount(i)<<1);
	}
	FWT_or(A,1,1<<n);
	FWT_or(B,1,1<<n);
	for(int i=0;i<(1<<n);++i){
		A[i]*=B[i];
	}
	FWT_or(A,-1,1<<n);
	for(int i=0;i<(1<<n);++i){
		cout<<(char)('0'+(A[i]>>(__builtin_popcount(i)<<1)&3));	
	}
	cout<<'\n';
	return 0;
}