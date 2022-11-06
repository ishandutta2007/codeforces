#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
int a,b,c;
int main(){
	cin>>a>>b>>c;
	b--;c-=2;
	cout<<min(a,min(b,c))*3+3<<endl;
	return 0;
}