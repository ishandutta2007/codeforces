#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
#define N 200020
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
int n,a[N],ans; 
set<ll> s;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	s.insert(0);
	ll x=0;
	for(int i=1;i<=n;++i){
		x+=a[i];
		if(s.count(x)){
			s.clear();
			s.insert(0);
			++ans,x=a[i];
		}
		s.insert(x);
	}
	printf("%d\n",ans);
	return 0;
}