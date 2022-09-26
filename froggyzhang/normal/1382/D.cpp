#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 4020
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,p[N],ok[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=(n<<1);++i){
			p[i]=read();
		}
		int now=p[1],len=1;
		vector<int> qwq;
		for(int i=2;i<=(n<<1);++i){
			if(p[i]>now){
				qwq.push_back(len);
				now=p[i],len=1;
			}
			else{
				++len;
			}
		}
		qwq.push_back(len);
		memset(ok,0,sizeof(ok));
		ok[0]=1;
		for(auto x:qwq){
			for(int i=n;i>=x;--i){
				ok[i]|=ok[i-x];
			}
		}
		printf(ok[n]?"YES\n":"NO\n");
	}
	return 0;
}