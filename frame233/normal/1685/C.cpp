#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
char s[N];int pre[N],st[N];
void MAIN(){
	int n;read(n);scanf("%s",s+1),n*=2;
	int p1=-1,p2=-1;
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+(s[i]=='('?1:-1);
		if(pre[i]<0)p2=i,p1=p1==-1?i:p1;
	}
	if(p1==-1)return puts("0"),void();
	int L=std::max_element(pre,pre+p1)-pre+1,R=std::max_element(pre+p2,pre+n+1)-pre,p=std::max_element(pre+1,pre+n+1)-pre;
	std::reverse(s+L,s+R+1);
	for(int i=1,cur=0;i<=n;++i){
		cur+=s[i]=='('?1:-1;
		if(cur<0)return printf("2\n%d %d\n%d %d\n",1,p,p+1,n),void();
	}
	printf("1\n%d %d\n",L,R);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}