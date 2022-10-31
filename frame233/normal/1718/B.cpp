#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;
ll f[50];int cnt[50],cc[50];bool can[50];
bool check(){
	memcpy(cc,cnt,sizeof(cc));
	if(!cc[0]&&cc[1])++cc[0],--cc[1];
	int p=0;while(cc[p])++p;
	for(int i=p;i<50;++i)if(cc[i])return 0;
	for(int i=0;i<50;++i)if(cc[i]>1)return 0;
	return 1;
}
void MAIN(){
	int k;read(k);memset(cnt,0,sizeof(cnt)),memset(can,0,sizeof(can));
	for(int i=1,x;i<=k;++i){
		read(x);int las=-1;
		for(int j=49;j>=0;--j)if(x>=f[j]){
			x-=f[j],++cnt[j],las=j;
		}
		if(las!=-1)can[las]=1;
	}
	if(check())return puts("YES"),void();
	for(int i=49;i>=3;i-=2)if(can[i]){
		--cnt[i];
		for(int j=i-1;j>=4;j-=2)++cnt[j];
		++cnt[0],++cnt[2];
		if(check())return puts("YES"),void();
		++cnt[i];
		for(int j=i-1;j>=4;j-=2)--cnt[j];
		--cnt[0],--cnt[2];
	}
	puts("NO"),void();
}
int main(){
	f[0]=f[1]=1;for(int i=2;i<50;++i)f[i]=f[i-2]+f[i-1];
	int _;read(_);
	while(_--)MAIN();
	return 0;
}