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
int n;
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	printf("3\n");
	printf("R %d\n",n-1);
	printf("L %d\n",n);
	printf("L %d\n",2);
	return 0;
}