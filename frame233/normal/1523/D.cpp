#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int read_str(char *s){
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

typedef long long ll;
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=200005;
ll a[N];
char s[N];
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
int cnt[1<<15],all[65],pos,C[1<<15];
int main(){
	for(int i=1;i<1<<15;++i)C[i]=C[i>>1]+(i&1);
	int n,m,p;read(n,m,p);
	for(int i=1;i<=n;++i){
		read_str(s);
		for(int j=0;j<m;++j)if(s[j]=='1')a[i]|=1LL<<j;
	}
	int ans=0;ll res=0;
	for(int T=0;T<60;++T){
		int x=rnd()%n+1;ll st=a[x];
		pos=0;for(int i=0;i<m;++i)if(st>>i&1)all[pos++]=i;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;++i){
			int cur=0;
			for(int j=0;j<pos;++j)if(a[i]>>all[j]&1)cur|=1<<j;
			++cnt[cur];
		}
		for(int i=pos-1;i>=0;--i)for(int j=(1<<pos)-1;j>=0;--j)if(!(j>>i&1))cnt[j]+=cnt[j^(1<<i)];
		for(int st=0;st<1<<pos;++st)if(cnt[st]>=(n+1)/2){
			if(C[st]>ans){
				ans=C[st],res=0;
				for(int i=0;i<pos;++i)if(st>>i&1)res|=1LL<<all[i];
			}
		}
	}
//	printf("%d\n",ans);
	for(int i=0;i<m;++i)printf("%lld",res>>i&1);
	printf("\n");
	return 0;
}