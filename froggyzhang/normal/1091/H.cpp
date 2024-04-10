#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
const int mx=200000;
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
int n,p[N],pn,sg[N],m;
bool ntp[N];
bitset<N> b[100],g;
void init(int n){
	ntp[1]=true;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=i;
		for(int j=1;p[j]*i<=n;++j){
			ntp[p[j]*i]=true;
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	init(mx);
	n=read(),m=read();
	for(int i=1;i<=pn;++i){
		g[p[i]]=1;
		for(int j=i;j<=pn;++j){
			if(1LL*p[i]*p[j]>mx)break;
			g[p[i]*p[j]]=1;
		}
	}
	g[m]=0;
	for(int i=0;i<=mx;++i){
		for(int j=0;;++j){
			if(!b[j][i]){
				sg[i]=j;
				break;
			}
		}
		b[sg[i]]|=(g<<i);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int x=read(),y=read(),z=read();
		ans^=sg[y-x-1]^sg[z-y-1];
	}
	if(ans){
		printf("Alice\nBob\n");
	}
	else{
		printf("Bob\nAlice\n");
	}
	return 0;
}