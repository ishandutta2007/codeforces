#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;
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
int n;
string s[N];
map<string,int> mp;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		cin>>s[i];
	}
	for(int i=n;i>=1;--i){
		if(mp.count(s[i]))continue;
		cout<<s[i]<<endl;
		mp[s[i]]=1;
	}
	return 0;
}