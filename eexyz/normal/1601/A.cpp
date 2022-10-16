#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define N 1000004
char buf[100000],*p1=buf,*p2=buf,ch;
int result;
#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
inline int read(){
    ch=getc();result=0;
    while (ch<'0'||ch>'9') ch=getc();
    while (ch>='0'&&ch<='9') result=result*10+(ch^48),ch=getc();
    return result;
}
int a[N],b[N],x,y,n,T,i,j,c[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=0;i<=30;++i)c[i]=0;
		for(i=1;i<=n;++i){
			cin>>a[i];
			for(j=0;j<30;++j)if((a[i]>>j)&1)++c[j];
		}
		x=0;for(i=0;i<30;++i)x=gcd(x,c[i]);
		if(x==0){for(i=1;i<=n;++i)cout<<i<<" ";cout<<"\n";}
		else{
		for(i=1;i<=x;++i)
			if(x%i==0)cout<<i<<" ";
		cout<<"\n";
		}
	}
}