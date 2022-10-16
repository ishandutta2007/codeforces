#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n;
string A,B,C;
string Get(string &a,string &b,char c,int t){
	string ans="";
	int i=0,j=0;
	for(;i<2*n||j<2*n;){
		while(i<2*n&&(!t||a[i]!=c))ans+=a[i],++i;
		while(j<2*n&&(!t||b[j]!=c))ans+=b[j],++j;
		if(t)ans+=c,--t;
		++i,++j;
	}
	return ans;
}
string Solve(){
	n=read();
	cin>>A;
	cin>>B;
	cin>>C;
	int a0=0,a1=0,b0=0,b1=0,c0=0,c1=0;
	for(int i=0;i<2*n;++i){
		if(A[i]=='0')++a0;
		else ++a1;
		if(B[i]=='0')++b0;
		else ++b1;
		if(C[i]=='0')++c0;
		else ++c1;
	}
	if(min(a0,b0)>=n)return Get(A,B,'0',min(a0,b0));
	if(min(a0,c0)>=n)return Get(A,C,'0',min(a0,c0));
	if(min(c0,b0)>=n)return Get(B,C,'0',min(c0,b0));
	
	if(min(a1,b1)>=n)return Get(A,B,'1',min(a1,b1));
	if(min(a1,c1)>=n)return Get(A,C,'1',min(a1,c1));
	if(min(c1,b1)>=n)return Get(B,C,'1',min(c1,b1));
	
	assert(false);
}
int main(){
	T=read();
//	T=1000;
	while(T--){
	//	assert(Solve().length()<=3*n);
		cout<<Solve()<<endl;
	}
	return 0;
}