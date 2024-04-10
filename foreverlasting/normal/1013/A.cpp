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
int n;
int suma,sumb;
int main(){
	n=read();
	for(res i=1;i<=n;i++){
		res x=read();
		suma+=x;
	}
	for(res i=1;i<=n;i++){
		res x=read();
		sumb+=x;
	}
	if(suma<sumb)puts("No");
	else puts("Yes");
	return 0;
}