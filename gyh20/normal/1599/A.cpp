#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[200002],o;
char s[200002],O[2];
ll sl,sr;
int main(){
	n=read(),O[0]='L',O[1]='R';
	for(re int i=1;i<=n;++i)a[i]=read();
	scanf("%s",s+1);
	sort(a+1,a+n+1);
	re int pos=1,p1=1;
	for(re int i=2;i<=n;++i)pos+=s[i]==s[i-1];
	reverse(a+1,a+pos);
	for(re int i=1;i<=n;++i){
		if(s[i]!=s[i-1]){
			if(s[i]=='L')sl+=a[pos];
			else sr+=a[pos];
			printf("%d %c\n",a[pos],s[i]);
			++pos;
		}
		else{
			if(s[i]=='L'&&sr+a[p1]<sl)printf("%d R\n",a[p1]),sr+=a[p1];
			else if(s[i]=='L')printf("%d L\n",a[p1]),sl+=a[p1];
			else if(s[i]=='R'&&sl+a[p1]<sr)printf("%d L\n",a[p1]),sl+=a[p1];
			else printf("%d R\n",a[p1]),sr+=a[p1];
			++p1;
		}
	}
}