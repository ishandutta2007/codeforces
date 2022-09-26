#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
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
ll k;
const char s[12]="codeforces";
int a[13]; 
inline ll check(){
	ll tmp=1;
	for(int i=0;i<10;++i){
		tmp*=a[i];
	}
	return tmp;
}
int main(){
	k=read();
	for(int i=0;i<10;++i){
		a[i]=1;
	}
	int now=0;
	while(check()<k){
		++a[now];
		now=(now+1)%10;
	}
	for(int i=0;i<10;++i){
		while(a[i]--)putchar(s[i]);
	}
	return 0;
}