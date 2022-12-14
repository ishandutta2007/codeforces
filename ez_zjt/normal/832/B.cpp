#include <cstdio>
#include <cstring>
#define MAXN 1000010

int n;
bool w[1000]={0};
char pattern[MAXN];
int pos;

void init(){
	static char str[100];
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++)
		w[str[i]]=1;
	scanf("%s",pattern+1);
	n=strlen(pattern+1);
	pos=0;
	for(int i=1;i<=n;i++)
		if(pattern[i]=='*'){
			pos=i;
			break;
		}
}

bool query(){
	static char ask[MAXN];
	scanf("%s",ask+1);
	int m=strlen(ask+1);
	if(!pos){
		if(n!=m) return 0;
		for(int i=1;i<=n;i++)
			if(pattern[i]=='?'){
				if(!w[ask[i]]) return 0;
			}else{
				if(pattern[i]!=ask[i]) return 0;
			}
		return 1;
	}else{
		if(n-1>m) return 0;
		for(int i=1;i<pos;i++)
			if(pattern[i]=='?'){
				if(!w[ask[i]]) return 0;
			}else{
				if(pattern[i]!=ask[i]) return 0;
			}
		for(int i=n;i>pos;i--)
			if(pattern[i]=='?'){
				if(!w[ask[m-n+i]]) return 0;
			}else{
				if(pattern[i]!=ask[m-n+i]) return 0;
			}
		for(int i=pos;i<=m-n+pos;i++)
			if(w[ask[i]]) return 0;
		return 1;
	}
}

int main(){
//#ifndef ONLINE_JUDGE
//	freopen("B.in","r",stdin);
//#endif
	init();
	int m;
	scanf("%d",&m);
	while(m--)
		if(query())
			puts("YES");
		else
			puts("NO");
	return 0;
}