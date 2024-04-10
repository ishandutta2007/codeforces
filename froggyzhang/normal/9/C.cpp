#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
int n,a[123],p;
int ans,ok;
int main(){
	n=read();
	while(n)a[++p]=n%10,n/=10;
	for(int i=p;i>=1;--i){
		if(a[i]>1)ok=1;
		ans<<=1;
		if(ok||a[i])++ans;
	}
	cout<<ans<<endl;
	return 0;
}