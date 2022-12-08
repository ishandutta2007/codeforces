#include<bits/stdc++.h>
using namespace std;
#define fl fwrite(o_str,1,top,stdout),top=0
const int MAXL=1<<22;
char i_str[MAXL],*i_s,*i_t;
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline int read() {
	int x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?-x:x;
}
int fa[30],t[30],T[30];
char s[1000010];
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main() {
	int M,cnt=0;
	scanf("%d",&M);
	for(int i=0;i<26;i++)fa[i]=i;
	for(int i=1;i<=M;i++) {
		memset(t,0,sizeof(t));
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int j=1;j<=n;j++)
			T[s[j]-'a']++,t[s[j]-'a']++;
		for(int j=0;j<26;j++)
			for(int k=0;k<26;k++)
				if(t[j]&&t[k])fa[get(j)]=get(k);
	}
	for(int i=0;i<26;i++)
		if(T[i]&&fa[i]==i)cnt++;
	printf("%d\n",cnt);
	return 0;
}