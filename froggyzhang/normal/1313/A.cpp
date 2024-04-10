#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,a,b,c;
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read();
		if(a<b)swap(a,b);
		if(b<c)swap(b,c);
		if(a<b)swap(a,b);
		int ans=0;
		if(a>0)--a,++ans;
		if(b>0)--b,++ans;
		if(c>0)--c,++ans;
		if(a>0&&b>0)--a,--b,++ans;
		if(a>0&&c>0)--a,--c,++ans;
		if(b>0&&c>0)--b,--c,++ans;
		if(a>0&&b>0&&c>0)--a,--b,--c,++ans;
		cout<<ans<<endl;
	}
	return 0;
}