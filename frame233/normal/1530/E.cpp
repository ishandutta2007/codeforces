#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int read_str(char *s){
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}
const int N=100005;
char s[N],t[N];
int _cnt[26],cnt[26];
void MAIN(){
	int n=read_str(s+1);t[n+1]=0;
	bool flag=true;for(int i=1;i<=n;++i)flag&=s[i]==s[1];
	if(flag)return printf("%s\n",s+1),void();
	memset(_cnt,0,sizeof(_cnt));for(int i=1;i<=n;++i)++_cnt[s[i]-97];
	for(int i=0;i<26;++i)if(_cnt[i]==1){
		t[1]=i+97;int cur=1;
		for(int j=0;j<26;++j)if(i!=j)for(int k=0;k<_cnt[j];++k)t[++cur]=j+97;
		return printf("%s\n",t+1),void();
	}
	for(int i=0;i<26;++i)if(_cnt[i]){
		if(_cnt[i]>=2){
			auto check1=[&](){
				memcpy(cnt,_cnt,sizeof(cnt)),cnt[i]-=2;
				t[1]=i+97,t[2]=i+97;
				bool tag=false;
				for(int j=3;j<=n;++j){
					if(!tag||!cnt[i]){
						for(int k=i+1;k<26;++k)if(cnt[k]){t[j]=k+97,--cnt[k],tag=true;break;}
						if(!tag)return false;
					}
					else if(cnt[i])t[j]=i+97,--cnt[i],tag=false;
				}
				return true;
			};
			if(check1())return printf("%s\n",t+1),void();
		}
		for(int j=i+1;j<26;++j)if(_cnt[j]){
			int o=-1;
			for(int k=i;k<26;++k)if(_cnt[k]&&i!=k&&j!=k){o=k;break;}
			if(o!=-1){
				memcpy(cnt,_cnt,sizeof(cnt));
				t[1]=i+97,t[2]=j+97;int cur=2;--cnt[i],--cnt[j];
				for(int j=0;j<cnt[i];++j)t[++cur]=i+97;
				cnt[i]=0,--cnt[o],t[++cur]=o+97;
				for(int j=0;j<26;++j)for(int k=0;k<cnt[j];++k)t[++cur]=j+97;
				return printf("%s\n",t+1),void();
			}
			else{
				memcpy(cnt,_cnt,sizeof(cnt));
				t[1]=i+97,t[2]=j+97;int cur=2;
				for(int k=1;k<cnt[j];++k)t[++cur]=j+97;
				for(int k=1;k<cnt[i];++k)t[++cur]=i+97;
				return printf("%s\n",t+1),void();
			}
		}
	}
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}