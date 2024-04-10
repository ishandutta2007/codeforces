#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll; 
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
char s[333333];
int n;
ll tot[30][30],cnt[30],ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		int c=s[i]-'a';
		for(int j=0;j<26;++j){
			tot[j][c]+=cnt[j];
		}
		++cnt[c];
	}
	for(int i=0;i<26;++i){
		ans=max(ans,cnt[i]);
		for(int j=0;j<26;++j){
			ans=max(ans,tot[i][j]);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}