#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 200000
using namespace std;
char s[N],S[2];int n,l,f[N],b[N],a[26][26],r[26],ans;
int main(){
	scanf("%s",s);l=strlen(s);
	scanf("%d",&n);
	rep(i,1,l)b[i]=s[i-1]-'a';
	rep(i,1,n){
		scanf("%s",S);
		a[S[0]-'a'][S[1]-'a']=1;
		a[S[1]-'a'][S[0]-'a']=1;
	}
	rep(i,1,l){
		rep(j,0,25)if(!a[b[i]][j])f[i]=max(f[i],r[j]+1);
		r[b[i]]=max(r[b[i]],f[i]);
	}
	rep(i,1,l)ans=max(ans,f[i]);
	printf("%d\n",l-ans);
}