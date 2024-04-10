#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;
int a[N];
void MAIN(){
	int n;read(n);
	int s=0;for(int i=1;i<=n;++i)read(a[i]),s^=a[i];
	if(s)return puts("NO"),void();
	std::vector<int> ans;
	if(n%2){
		for(int i=1;i<=n-2;i+=2)ans.pb(i);
		for(int i=n-4;i>=1;i-=2)ans.pb(i);
	}
	else{
		bool flag=0;
		for(int i=1,s=0;i<=n;++i){
			s^=a[i];
			if(i%2&&!s){
				flag=1;
				for(int j=1;j<=i-2;j+=2)ans.pb(j);
				for(int j=i-4;j>=1;j-=2)ans.pb(j);
				for(int j=n;j>=i+3;j-=2)ans.pb(j-2);
				for(int j=i+5;j<=n;j+=2)ans.pb(j-2);
				break;
			}
		}
		if(!flag)return puts("NO"),void();
	}
	printf("YES\n%d\n",SZ(ans));for(auto it:ans)printf("%d ",it);
	printf("\n");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}