#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
std::string move(int x,int y){
	printf("%d %d\n",x,y),fflush(stdout);
	std::string s;std::cin>>s;return s;
}
void MAIN(){
	int qwq=0;
	if(move(1,8)=="Done")return;
	for(int i=1;i<=8;++i){
		if(qwq){
			std::string tmp=move(i,qwq);
			if(tmp=="Done")return;
			else if(tmp=="Down"||tmp=="Down-Right"||tmp=="Down-Left")continue;
		}
		int j=1;
		for(;;){
			std::string tmp=move(i,j);
			if(tmp=="Done")return;
			if(tmp=="Down"||tmp=="Down-Right"||tmp=="Down-Left")break;
			if(tmp=="Up"||tmp=="Up-Left"||tmp=="Up-Right")j=j%2?1:0;
			if(j+1<=8)j+=1;
			else break;
		}
		qwq=j+(j==1);
	}
	move(10,10);
//	assert(0);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}