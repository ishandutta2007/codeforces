#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
#define N 200020
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
int n,las;
ll a[N],s[N],ans;
map<ll,int> mp;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]+a[i];
	}
	mp[0]=0;
	las=-1;
	for(int i=1;i<=n;++i){
		if(mp.count(s[i])){
			las=max(las,mp[s[i]]);
		}
		mp[s[i]]=i;
		ans+=i-las-1;
	}
	cout<<ans<<endl;
	return 0;
}