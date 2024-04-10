#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
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
map<ll,int> mp; 
int T;
void Solve(){
	ll n=read();
	int gu=0;
	while(true){
		if(mp.count(n)){
			printf("%d\n",mp[n]+gu);
			return;
		}
		if((n<<1)>2e18){
			printf("-1\n");
			return;
		}
		n<<=1,++gu;
	}
}
int main(){
	ll tmp=1;
	int step=0;
	while(true){
		mp[tmp]=step;
		++step;
		if(tmp*6.0>2e18)break;
		tmp*=6;
	}
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}