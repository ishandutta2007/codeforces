#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
void MAIN(){
	int n;read(n);
	if(n<100)printf("%d\n",n%10);
	else{
		std::vector<int> vec;
		while(n)vec.pb(n%10),n/=10;
		printf("%d\n",*std::min_element(vec.begin(),vec.end()));
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}