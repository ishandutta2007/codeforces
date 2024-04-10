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
int l,r;
int vis[11];
bool check(int x){
	memset(vis,0,sizeof(vis));
	while(x){
		if(vis[x%10])return false;
		vis[x%10]=1;
		x/=10;
	}
	return true;
}
int main(){
	l=read(),r=read();
	for(int i=l;i<=r;i++){
		if(check(i)){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}