#include <bits/stdc++.h>
using namespace std;
unsigned long long ans;
int n,val[300010];
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) val[i]=read();
	sort(val+1,val+n+1); 
	for(int l=1,r=n;l<r;l++,r--){
		ans+=(val[l]+val[r])*(val[l]+val[r]);
	}cout<<ans;
}