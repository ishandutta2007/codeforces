//2018.7.30 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline int _max(res x,res y){
    return x>y?x:y;
}
inline int _min(res x,res y){
    return x<y?x:y;
}
const int N=1e5+10;
int n,a[N],mp[N],x,maxn;
int main(){
	n=read(),x=read();
	for(res i=1;i<=n;i++){
		a[i]=read();
		maxn=_max(a[i],maxn);
		if(mp[a[i]]){puts("0");return 0;}
		mp[a[i]]=1;
	}
	for(res i=1;i<=n;i++)if(mp[a[i]&x]&&((a[i]&x)!=a[i])){puts("1");return 0;}
	memset(mp,0,sizeof(mp));
	for(res i=1;i<=n;i++){
	    a[i]&=x;
	    if(mp[a[i]]){puts("2");return 0;}
	    mp[a[i]]=1;
	}
	puts("-1");
	return 0;
}