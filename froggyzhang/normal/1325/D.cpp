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
ll u,v;
int main(){
	cin>>u>>v;
	if(v<u||((v-u)&1)){
		printf("-1\n");
		return 0;
	}
	if(u==0){
		if(v==0){
			printf("0\n");
		}
		else{
			printf("%d\n%lld %lld\n",2,v/2,v/2);
		}
	}
	else if(u==v){
		printf("%d\n%lld\n",1,u);
	}
	else{
		if(u&((v-u)/2)){
			printf("%d\n",3);
			printf("%lld %lld %lld\n",u,(v-u)/2,(v-u)/2);
		}
		else{
			printf("%d\n",2);
			printf("%lld %lld\n",u+(v-u)/2,(v-u)/2);
		}
	}
	return 0;
}