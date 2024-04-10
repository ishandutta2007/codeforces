#include<cstdio>
#include<cstring>
#include<iostream>
#define in inline
#define re register
using namespace std;
in int read() {
	re int t=0;
	re char v=getchar();	
	while(v<'0'||v>'9'){
	v=getchar();
	}	
	while(v>='0'&&v<='9'){		
	t=(t<<3)+(t<<1)+(v^48);		
	v=getchar();	}
	return t;
}
char s[300005];
int l,r,cnt;
int main(){
	scanf("%s",s);
	l=0;
	r=strlen(s)-1;
	while(l<=r){
		if(l==r){
			putchar('0');
			return 0;
		}
		cnt=2;
		if(s[l]!=s[r]){
			putchar('0');
			return 0;
		}
		while(s[l+1]==s[l]&&l<r)++l,++cnt;
		while(s[r-1]==s[r]&&r>l)--r,++cnt;
		++l;
		--r;
		if(r<l){
			printf("%d",cnt);
			return 0;
		}
		if(cnt<3){
			putchar('0');
			return 0;
		}
		
	}
}