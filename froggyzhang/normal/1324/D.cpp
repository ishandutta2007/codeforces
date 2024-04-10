#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 200020
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,a[N],l,r;
ll ans;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		a[i]-=read();
	} 
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<r){
		while(l<r&&a[l]+a[r]<=0)++l;
		ans+=r-l;	
		--r;
	}
	cout<<ans<<endl;
	return 0;
}