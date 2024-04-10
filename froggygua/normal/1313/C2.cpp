#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 5000500
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
int n;
ll a[N],mx,f[N],g[N],top,pos;
pair<ll,int> st[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	f[1]=a[1];
	st[++top]=make_pair(a[1],1);
	for(int i=2;i<=n;i++){
		int tot=1;
		ll now=f[i-1];
		while(top&&st[top].first>a[i]){
			tot+=st[top].second;
			now-=st[top].second*st[top].first;
			--top;
		}
		now+=tot*a[i];
		st[++top]=make_pair(a[i],tot);
		f[i]=now;
	}
	g[n]=a[n];
	top=0;
	st[++top]=make_pair(a[n],1);
	for(int i=n-1;i>=1;i--){
		int tot=1;
		ll now=g[i+1];
		while(top&&st[top].first>a[i]){
			tot+=st[top].second;
			now-=st[top].second*st[top].first;
			--top;
		}
		now+=tot*a[i];
		st[++top]=make_pair(a[i],tot);
		g[i]=now;
	}
	for(int i=1;i<=n;i++){
		if(f[i]+g[i]-a[i]>mx){
			pos=i;
			mx=f[i]+g[i]-a[i];
		}
	}
	for(int i=pos-1;i>=1;i--){
		a[i]=min(a[i],a[i+1]);
	}
	for(int i=pos+1;i<=n;i++){
		a[i]=min(a[i],a[i-1]);
	}
	for(int i=1;i<=n;i++){
		printf("%I64d ",a[i]);
	}
	return 0;
}