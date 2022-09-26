#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
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
int n;
char s[N];
int a[15];
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='L'){
			for(int j=1;j<=10;j++){
				if(a[j]==0){
					a[j]=1;break;
				}
			}
		}
		else if(s[i]=='R'){
			for(int j=10;j>=1;j--){
				if(a[j]==0){
					a[j]=1;
					break;
				}
			}
		}
		else{
			int c=s[i]-'0';
			a[c+1]=0;
		}
	}
	for(int i=1;i<=10;i++){
		cout<<a[i];
	}
	return 0;
}