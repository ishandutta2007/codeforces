#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;
char s[N];int n,q;
inline bool check(int i){
	return i>=1&&s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c';
}
int main(){
	read(n,q);
	scanf("%s",s+1);char c;int cnt=0;
	for(int i=1;i+2<=n;++i)cnt+=check(i);
	int i;
	while(q--){
		read(i);do{c=getchar();}while(!isalpha(c));
		cnt-=check(i-2)+check(i-1)+check(i),s[i]=c;
		cnt+=check(i-2)+check(i-1)+check(i);
		printf("%d\n",cnt);
	}
	return 0;
}