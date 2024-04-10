#include<cstdio>
#include<queue>
#include<cstring>
#include<map>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
int pos[150002],num;
char s[150002];
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		num=0;
		for(re int i=1;i<=n-2;++i){
			if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')pos[++num]=i+1,s[i]='a';
			if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')if(s[i+3]=='o'&&i<=n-3)pos[++num]=i+1;else pos[++num]=i+2,s[i+2]='a';
		}
		printf("%d\n",num);
		for(re int i=1;i<=num;++i)printf("%d ",pos[i]);
	//	printf("%s\n",s+1);
		putchar('\n');
	}
}