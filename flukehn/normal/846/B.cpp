#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
typedef long long ll;
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=45*45+1000,inf=0x7fffffff;
int f[N],a[N];
int main(){
	int n=rd(),k=rd(),M=rd();
	rep(i,1,n*k+n)f[i]=inf;
	rep(i,1,k){
		a[i]=rd();
	}
	sort(a+1,a+k+1);
	rep(i,2,k+1)a[i]+=a[i-1];
	//cout<<f[1]<<" "<<f[2]+1<<" fff"<<endl;
	rep(t,1,n)per(j,n*k+n,1)rep(i,1,k){
		if(i==k)i++;
		if(j>=i&&f[j-i]!=inf)f[j]=min(f[j],f[j-i]+a[i]);
	}
	//rep(i,1,n*k)cout<<f[i]<<" \n"[i==n*k]; 
	per(i,n*k+n,0){
		if(f[i]<=M){
			cout<<i<<endl;
			return 0;
		}
	}
}