#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2000200
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
int T,d[N];
char s[N];
int init(){
	int len=strlen(s+1);
	for(int i=len;i>=1;--i){
		s[i<<1]=s[i],s[i<<1|1]='#';
	}
	s[1]='#',s[0]='*',s[len+1<<1]='?';
	return len<<1|1;
}
void Manacher(int n){
	int mx=0,po=0;
	for(int i=1;i<=n;++i){
		d[i]=(mx>i?min(mx-i,d[2*po-i]):1);
		while(s[i+d[i]]==s[i-d[i]])++d[i];
		if(d[i]+i>mx){
			mx=d[i]+i,po=i;
		}
	}
}
void Solve(){
	scanf("%s",s+1);
	int len=init();
	Manacher(len);
	int tmp=0;
	for(int i=1;i<=(len>>1);++i){
		if(s[i]^s[len-i+1]){
			break;
		}
		else ++tmp;
	}
	int ans1=0,ans2=0;
	for(int i=((len+1)>>1);i>tmp;--i){
		if(i-d[i]+1<=tmp+1){
			ans1=(i-tmp)*2-1;
			break;
		}
	}
	for(int i=((len+1)>>1);i<len-tmp+1;++i){
		if(i+d[i]-1>=len-tmp){
			ans2=(len-tmp-i+1)*2-1;
			break;
		}
	} 
	if(ans1>ans2){
		for(int i=1;i<=tmp+ans1;++i){
			if(s[i]^'#')putchar(s[i]);
		}
		for(int i=len-tmp+1;i<=len;++i){
			if(s[i]^'#')putchar(s[i]);
		}
	}
	else{
		for(int i=1;i<=tmp;++i){
			if(s[i]^'#')putchar(s[i]);
		}
		for(int i=len-tmp-ans2+1;i<=len;++i){
			if(s[i]^'#')putchar(s[i]);
		}
	}
	putchar('\n');
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}