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
int n;
int buf[111];
char s[111];
int Change(int l,int r){
	int num=0;
	for(int i=l;i<=r;i++){
		num=(num<<1)+(num<<3)+s[i]-'0';
	} 
	return num;
} 
int trans(int l,int r){
	int num=0;
	for(int i=l;i<=r;i++){
		num=num*26+s[i]-'A'+1;
	}
	return num;
}
void JB(int x){
	int p=0;
	while(x){
		if(x%26){
			buf[++p]=x%26;
		}
		else{
			buf[++p]=26;
		}
		x=x/26-(!(x%26));
	} 
	while(p)putchar(buf[p--]+'A'-1);
}
void solve(char *s){
	int len=strlen(s+1);
	int type=0,pos=0;
	if(s[1]=='R'&&s[2]>='1'&&s[2]<='9'){
		int tmp=3;
		while(tmp<=len&&!type){
			if(s[tmp]=='C')type=1,pos=tmp;
			else if(s[tmp]>='A'&&s[tmp]<='Z')break;
			++tmp;
		}
	}
	if(type){
		int x=Change(2,pos-1);
		int y=Change(pos+1,len);
		JB(y);
		printf("%d\n",x);
	}
	else{
		int w=1;
		while(s[w]>='A'&&s[w]<='Z')++w;
		int x=trans(1,w-1);
		int y=Change(w,len);
		printf("R%dC%d\n",y,x);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		solve(s);
	}
	return 0;
}