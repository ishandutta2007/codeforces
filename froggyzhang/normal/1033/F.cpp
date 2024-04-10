#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> poly;
int m,n,Q;
poly A;
void FWT(poly &f,string s){
	for(auto &c:s)c=tolower(c);
	for(int p=0;p<m;++p){
		int len=1<<p;
		for(int k=0;k<(1<<m);k+=len<<1){
			for(int i=k;i<k+len;++i){
				int t0=f[i],t1=f[i|len];
				if(s[p]=='a'){
					f[i]=t0+t1,f[i|len]=t1;
				}
				else if(s[p]=='o'){
					f[i]=t0,f[i|len]=t0+t1;
				}
				else{
					f[i]=t0+t1,f[i|len]=t0-t1;	
				}
			}	
		}	
	}
}
void iFWT(poly &f,string s){
	for(auto &c:s)c=tolower(c);
	for(int p=0;p<m;++p){
		int len=1<<p;
		for(int k=0;k<(1<<m);k+=len<<1){
			for(int i=k;i<k+len;++i){
				int t0=f[i],t1=f[i|len];
				if(s[p]=='a'){
					f[i]=t0-t1,f[i|len]=t1;
				}
				else if(s[p]=='o'){
					f[i]=t0,f[i|len]=t1-t0;
				}
				else{
					f[i]=(t0+t1)/2,f[i|len]=(t0-t1)/2;	
				}
			}	
		}	
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n>>Q;
	A.resize(1<<m);
	for(int i=1,x;i<=n;++i){
		cin>>x;
		++A[x];
	}
	while(Q--){
		string opt;
		cin>>opt;
		reverse(opt.begin(),opt.end());
		poly B=A;
		FWT(B,opt);
		for(int i=0;i<(1<<m);++i){
			B[i]*=B[i];
		}
		iFWT(B,opt);
		int z=0;
		for(int i=0;i<m;++i){
			if(opt[i]>='a'&&opt[i]<='z')z|=1<<i;
		}
		cout<<B[z]<<'\n';
	}
	return 0;
}