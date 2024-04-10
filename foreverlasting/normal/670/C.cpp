#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define res register int
#define inf 0x3f3f3f3f
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}
const int N=2*1e5+10;
int a[N],b[N*10];
int main(){
    int n=read();
    for(res i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    int m=read();
    for(res i=1;i<=m;i++)b[i]=read();
    int rbq=0,hentai=0,haha=1,v;
    for(res i=1;i<=m;i++){
        v=read();
        int k1=(upper_bound(a+1,a+1+n,b[i])-a)-(lower_bound(a+1,a+1+n,b[i])-a);
        int k2=(upper_bound(a+1,a+1+n,v)-a)-(lower_bound(a+1,a+1+n,v)-a);
        if(k1>rbq||(k1==rbq&&k2>hentai))rbq=k1,hentai=k2,haha=i;
    }
    printf("%d\n",haha);
}