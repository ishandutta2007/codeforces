#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
#define N 1000010
const ll inf=0x3f3f3f3f3f3f3f3fll;
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
int n,T,a[N],b[N];
bool Solve(){
	n=read();
	ll sum=0;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int i=1;i<=n;++i)sum+=a[i]-b[i];
	if(sum>0)return false;
	sum=0;
	ll mn=b[1];
	for(int i=1;i<=(n<<1)+1;++i){
		sum+=a[i%n+1]-b[i%n+1];
		mn=min(mn,b[i%n+1]+sum);
		if(mn<sum)return false;
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}