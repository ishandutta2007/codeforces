#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
int T;
ll n;
int main(){
	T=read();
	while(T--){
		n=read();
		int cnt=0;
		while((n>>(cnt+2))){
			cnt+=2;
		}
		ll tmp=n;
		if(n%3==1){
			printf("%lld\n",(1LL<<cnt)+(n-(1LL<<(cnt)))/3);
		}
		else{
			ll h=(1LL<<cnt)+(n-(1LL<<(cnt)))/3,ans=(1LL<<(cnt+1));
			if(n%3==2){
				int gg=0;
				while(h>=3){
					if((h&3)==1)ans|=(2LL<<gg);
					else if((h&3)==2)ans|=(3LL<<gg);
					else if((h&3)==3)ans|=(1LL<<gg);
					gg+=2;
					h>>=2;
				}
			}
			else{
				ans+=(1LL<<(cnt));
				int gg=0;
				while(h>=3){
					if((h&3)==1)ans|=(3LL<<gg);
					else if((h&3)==2)ans|=(1LL<<gg);
					else if((h&3)==3)ans|=(2LL<<gg);
					gg+=2;
					h>>=2;
				}
			}
			printf("%lld\n",ans);
		}
	}
	getchar(),getchar();
	return 0;
}