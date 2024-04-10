#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define N 1010
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
int n,m,p,ok;
string s[N],t,ans[N];
map<string,int> mp;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>s[i];
		t=s[i];
		reverse(t.begin(),t.end());
		if(mp.count(t)){
			ans[++p]=s[i],ans[++p]=t;
			mp.erase(t);
		}
		else{
			if(!ok){
				if(s[i]==t){
					ok=i;
				}
				else{
					mp[s[i]]=1;
				}
			}
			else{
				mp[s[i]]=1;
			}
		}
	}
	printf("%d\n",(p+(ok?1:0))*m);
	for(int i=1;i<=p;i+=2){
		cout<<ans[i];
	}
	if(ok)cout<<s[ok];
	for(int i=p;i>=2;i-=2){
		cout<<ans[i];
	}
	return 0;
}