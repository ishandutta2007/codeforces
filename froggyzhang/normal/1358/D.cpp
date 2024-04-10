#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 1000100
inline ll read(){
    ll x=0,f=1;
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
int n;
ll x,d[N],s[N],ans,now;
int main(){
	n=read(),x=read();
	for(int i=1;i<=n;++i){
		d[i]=read();
		d[i+n]=d[i];
	}
	for(int r=1,l=1;r<=(n<<1);++r){
		x-=d[r];
		now+=d[r]*(d[r]+1)/2;
		while(l<=(n<<1)&&x<0){
			now-=d[l]*(d[l]+1)/2;
			x+=d[l];
			++l;
		}
		if(x>d[l-1])continue;
		ans=max(ans,now+(d[l-1]+(d[l-1]-x+1))*x/2);
	}
	cout<<ans<<endl;
	return 0;
}