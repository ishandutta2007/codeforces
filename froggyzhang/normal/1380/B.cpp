#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
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
int T,n;
char s[N];
bool check(char A,char B){
	if(A=='R')return B=='S';
	if(A=='S')return B=='P';
	if(A=='P')return B=='R';
	return false; 
}
int calc(char c){
	int tot=0;
	for(int i=1;i<=n;++i){
		tot+=check(c,s[i]);
	}
	return tot;
}
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int R=calc('R');
		int P=calc('P');
		int S=calc('S');
		char QAQ='.';
		if(R>=P&&R>=S)QAQ='R';
		else if(P>=R&&P>=S)QAQ='P';
		else QAQ='S';
		for(int i=1;i<=n;++i){
			putchar(QAQ);
		}
		putchar('\n');
	}
	return 0;
}