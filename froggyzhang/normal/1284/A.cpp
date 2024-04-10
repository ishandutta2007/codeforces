#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
#define N 12345
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
int n,m,Q;
string a[N],b[N]; 
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	Q=read();
	while(Q--){
		int x=read();
		cout<<a[(x-1)%n+1]<<b[(x-1)%m+1]<<endl;
	}
	return 0;
}