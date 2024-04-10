#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
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
int n,Q,mp[2][N],cnt;
int main(){
	n=read(),Q=read();
	while(Q--){
		int x=read()-1,y=read();
		mp[x][y]^=1;
		if(mp[x][y]){
			cnt+=mp[x^1][y]+mp[x^1][y-1]+mp[x^1][y+1];
		}
		else{
			cnt-=mp[x^1][y]+mp[x^1][y-1]+mp[x^1][y+1];
		}
		if(!cnt){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}