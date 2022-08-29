#include<cstdio>
#include<cstring>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int n,a[32],b[32];
char s[100002],ans[32];
bool v[32];
inline int find(){
	for(re int i=1;i<=26;++i)if(!v[i])if((!b[i]&&!v[i])||(v[a[i]]&&!v[i]))return i;
	return 27;
}
signed main(){
	v[0]=1;
	int t=read();
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		bool ia=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(v,0,sizeof(v));
		v[0]=1;
		for(re int i=1;i<n;++i){
			if(!a[s[i]-'a'+1]||a[s[i]-'a'+1]==s[i+1]-'a'+1){
				a[s[i]-'a'+1]=s[i+1]-'a'+1;
			}
			else if(!b[s[i]-'a'+1]||b[s[i]-'a'+1]==s[i+1]-'a'+1){
				b[s[i]-'a'+1]=s[i+1]-'a'+1;
			}
			
			else{
				ia=1;
				puts("NO");
				break;
			}
			if(!a[s[i+1]-'a'+1]||a[s[i+1]-'a'+1]==s[i]-'a'+1){
				a[s[i+1]-'a'+1]=s[i]-'a'+1;
			}
			else if(!b[s[i+1]-'a'+1]||b[s[i+1]-'a'+1]==s[i]-'a'+1){
				b[s[i+1]-'a'+1]=s[i]-'a'+1;
			}
			
			else{
				ia=1;
				puts("NO");
				break;
			}
		}
		if(ia)continue;
		int k,tot=0;
		while((k=find())<27){
			while(1){
				v[k]=1;
				ans[++tot]=k;
				if(v[a[k]]&&v[b[k]])break;
				if(!v[a[k]]&&!v[b[k]]){
				ia=1;
				puts("NO");
				break;
			}
				if(!v[a[k]])k=a[k];
				else k=b[k];
			}
			if(ia)break;
		}
		for(re int i=1;i<=26;++i){
			if(!v[i]){
				ia=1;
				puts("NO");
				break;
			}
		}
		if(ia)continue;
		puts("YES");
		for(re int i=1;i<=26;++i)putchar(ans[i]+'a'-1);
		putchar('\n');
	}
}