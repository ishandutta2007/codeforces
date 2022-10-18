#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=1e5+5;
const int inf=1e9;
int n;
int a[N]; char b[N];
int l,r;
inline bool check(int i){
	for(int j=i-4;j<=i-1;j++) if(b[j]!=b[i-1]) return 0;
	return 1;
}
inline int get_max(int i){
	int x=-inf;
	for(int j=i-4;j<=i;j++) x=max(x,a[j]);
	return x;
}
inline int get_min(int i){
	int x=inf;
	for(int j=i-4;j<=i;j++) x=min(x,a[j]);
	return x;
}
int main(){
	l=-inf,r=inf;
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	scanf("%s",b+1);
	for(int i=5;i<=n;i++){
		int mx=get_max(i),mn=get_min(i);
		if(check(i)&&b[i-1]=='1'&&b[i]=='0') r=min(r,mn-1);
		else if(check(i)&&b[i-1]=='0'&&b[i]=='1')l=max(l,mx+1);
	}
	cout<<l<<' '<<r;
    return 0;
}