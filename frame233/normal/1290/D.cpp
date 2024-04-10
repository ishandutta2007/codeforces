#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1025;
std::vector<int> vec[N];int a[N],pos;bool used[N];
char ask(int x){
	printf("? %d\n",x+1),fflush(stdout);
	char ch;do{ch=getchar();}while(!isalpha(ch));
	return ch;
}
int main(){
	int n,k;read(n,k);int sz=k==1?1:k/2,c=n/sz;
	for(int s=0;s<c/2;++s){
		pos=0;
		for(int i=0,cur=s;i<c;++i){
			a[pos++]=cur;
			if(i%2==0)cur=(cur-i-1+c)%c;
			else cur=(cur+i+1)%c;
		}
		for(int i=0;i<pos;++i){
			for(int j=a[i]*sz;j<(a[i]+1)*sz;++j)if(!used[j]){
				if(ask(j)=='Y')used[j]=1;
			}
		}
		printf("R\n"),fflush(stdout);
	}
	printf("! %d\n",(int)std::count(used,used+n,0)),fflush(stdout);
	return 0;
}