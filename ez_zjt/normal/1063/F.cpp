#include <bits/stdc++.h>
using namespace std;

const int P=11451419,G=19;
const int MAXN=500010;

int n;
char str[MAXN];
int s[MAXN<<1];
bool f[2][MAXN<<1];
int tag[P];
int h[MAXN];

void init(){
	static int v[30];
	v[0]=rand()%810+1;
	for(int i=1;i<26;i++) v[i]=v[i-1]+rand()%810+1;
	random_shuffle(v,v+26);
	for(int i=1;i<=n;i++) s[i]=v[str[i]-'a'];
}

int main(){
#ifdef DEBUG
	freopen("F.in","r",stdin);
#endif
	scanf("%d",&n);
	scanf("%s",str+1);
	init();
	for(int i=1;i<=n;i++) f[1][i]=1,h[i]=s[i];
	for(int l=2;;l++){
		int cur=l&1,lst=cur^1;
		bool flag=0;
		for(int i=n;i>=1;i--){
			if(f[lst][i+l]) tag[h[i+l]]=l;
			flag|=(f[cur][i]=(tag[h[i]]==l || tag[h[i+1]]==l));
		}
		if(!flag){
			printf("%d\n",l-1);
			return 0;
		}
		for(int i=1;i<=n;i++)
			h[i]=(h[i]*G+s[i+l-1])%P;
	}
}