#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll a,b,c;
inline ll Abs(ll x){
	return x>=0?x:-x;
}
int main(){
	a=read(),b=read(),c=read();
	printf("First\n10000000000\n");
	fflush(stdout);
	int x=read();
	if(x==1)a+=1e10;
	else if(x==2)b+=1e10;
	else if(x==3)c+=1e10;
	else return 0;
	ll p=0;
	ll tmp[4]={a,b,c};
	sort(tmp,tmp+3);
	printf("%lld\n",p=(tmp[2]<<1)-tmp[1]-tmp[0]);
	fflush(stdout);
	x=read();
	if(x==1)a+=p;
	else if(x==2)b+=p;
	else if(x==3)c+=p;
	else return 0;
	printf("%lld\n",min(Abs(a-b),Abs(b-c)));
	fflush(stdout);
	x=read();
	return 0;
}