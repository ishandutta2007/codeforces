#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 5050
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
int n,a,b;
int tot,las,dp[N];
char s[N];
struct SAM{
	int ch[26];
	int fa,len;
}t[N<<1];
void Insert(int c){
	int u=++tot;
	t[u].len=t[las].len+1;
	int p=las;
	while(p&&!t[p].ch[c]){
		t[p].ch[c]=u;
		p=t[p].fa;
	}
	if(!p){
		t[u].fa=1;
	} 
	else{
		int q=t[p].ch[c];
		if(t[q].len==t[p].len+1){
			t[u].fa=q;
		}
		else{
			int clone=++tot;
			t[clone]=t[q];
			t[clone].len=t[p].len+1;
			while(p&&t[p].ch[c]==q){
				t[p].ch[c]=clone;
				p=t[p].fa;
			}
			t[u].fa=t[q].fa=clone;
		}
	}
	las=u;
}
int main(){
	n=read(),a=read(),b=read();
	memset(dp,0x3f,sizeof(dp));
	scanf("%s",s+1);
	tot=las=1;
	dp[0]=0;
	for(int i=1;i<=n;++i){
		Insert(s[i]-'a');
		dp[i]=min(dp[i],dp[i-1]+a);
		int u=1;
		for(int j=i+1;j<=n;++j){
			int c=s[j]-'a';
			if(t[u].ch[c]){
				dp[j]=min(dp[j],dp[i]+b);
				u=t[u].ch[c];
			}
			else break;
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}