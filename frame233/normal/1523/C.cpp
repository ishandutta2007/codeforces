#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1005;
int st[N],top;
void MAIN(){
	int n;read(n);
	top=0;
	for(int i=1,x;i<=n;++i){
		read(x);
		if(x==1)st[++top]=1;
		else{
			while(st[top]+1!=x)--top;
			++st[top];
		}
		for(int j=1;j<top;++j)printf("%d.",st[j]);
		printf("%d\n",st[top]);
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}