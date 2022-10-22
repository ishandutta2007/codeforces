#include<bits/stdc++.h>
using namespace std;
#define res int
#define LL long long
#define gc getchar
#define Pair pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
inline int read(){
    res s=0,w=1,ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
inline void solve(){
	int n=read(),m=read();
	LL ans=(LL)n*(m-1);
	if(m==1){
		ans+=n-1;
	}
	printf("%lld\n",ans);
}
int main(){
	int T=1;
	while(T--)solve();
}