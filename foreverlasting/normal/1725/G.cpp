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
#define INF 1000000000000000ll
inline int read(){
    res s=0,w=1,ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
const int N=1e5+10;
inline void solve(){
	int n=read();
	LL l=1,r=INF,ret=0;
	while(l<=r){
		LL mid=(l+r)>>1;
		LL t=mid>=1;
		t+=mid>=4;
		t+=(mid-2)/4+1;
		t=mid-t;
		if(t<n)l=mid+1;
		else r=mid-1,ret=mid;
	}
	printf("%lld\n",ret);
}
int main(){
	int T=1;
	while(T--)solve();
}