#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
int n,cnt[22];
ll ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read();
		for(int j=0;j<=20;++j){
			if((x>>j)&1)++cnt[j];
		}
	}
	for(int i=1;i<=n;++i){
		int x=0;
		for(int j=0;j<=20;++j){
			if(cnt[j])x|=(1<<j),--cnt[j];
		}
		ans+=1LL*x*x;
	}
	cout<<ans<<endl;
	return 0;
}