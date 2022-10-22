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
const int N=1e5+10;
int n,a[N],D;
inline void solve(){
	n=read(),D=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1,greater());
	int id=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=D){id=i;break;}
	}
	if(!id){printf("%d\n",n);return;}
	int p=n,ans=0;
	for(int i=1;i<=n;i++){
		int u=D/a[i];
		u++;
		if(p-i+1<u)break;
		ans++;
		p-=u-1;
	}
	printf("%d\n",ans);
}
int main(){
	int T=1;
	while(T--)solve();
}