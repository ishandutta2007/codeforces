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
int T;
char s[12][12];
inline char p(char c){
	return (c-'1'+1)%9+'1';
}
int main(){
	T=read();
	while(T--){
		for(int i=1;i<=9;++i){
			scanf("%s",s[i]+1);
		}
		s[1][1]=p(s[1][1]);
		s[2][4]=p(s[2][4]);
		s[3][7]=p(s[3][7]);
		s[4][2]=p(s[4][2]);
		s[5][5]=p(s[5][5]);
		s[6][8]=p(s[6][8]);
		s[7][3]=p(s[7][3]);
		s[8][6]=p(s[8][6]);
		s[9][9]=p(s[9][9]);
		for(int i=1;i<=9;++i){
			for(int j=1;j<=9;++j){
				putchar(s[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}