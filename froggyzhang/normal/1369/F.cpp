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
int T,t1,t2;
inline int check(ll s,ll e,int t1,int t2){
	if(s>e)return s&1?t1:t2;
	if(t1&&t2)return check(s,e>>1,~e&1,e&1);
	if(t1&&!t2)return check(s,e>>1,1,1);
	if(!t1&&t2)return check(s,e>>1,0,1); 
	return check(s,e>>1,1,1);
}
int main(){
	T=read();
	t1=1,t2=0;
	while(T--){
		ll s=read(),e=read();
		int f1=0,f2=0;
		if(check(s,e,0,0))f1=t1;
		else f1=t2;
		if(check(s,e,1,1))f2=t1;
		else f2=t2;
		swap(f1,t1),swap(f2,t2);
	}
	printf("%d %d\n",t2,t1);
	return 0;
}