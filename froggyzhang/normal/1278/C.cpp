#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
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
int n,T,a[N],b[N],qwq;
map<int,int> mp;
int main(){
	T=read();
	while(T--){
		n=read();qwq=0;
		mp.clear();
		int ans=2*n;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]==1)++qwq;
			else --qwq;
		}
		for(int i=1;i<=n;i++){
			b[i]=read();
			if(b[i]==1)++qwq;
			else --qwq;
		}
		mp[0]=0;
		int now=0;
		for(int i=n;i>=1;i--){
			if(a[i]==1)++now;
			else --now;
			if(!mp.count(now))mp[now]=n-i+1;
		}
		now=0;
		if(mp.count(qwq))ans=min(ans,mp[qwq]); 
		for(int i=1;i<=n;i++){
			if(b[i]==1)++now;
			else --now;
			if(mp.count(qwq-now))ans=min(ans,mp[qwq-now]+i);
		}
		cout<<ans<<endl;
	}
	return 0;
}