#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
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
int pos;
string s,t;
int main(){
	cin>>s;
	t="heidi";
	for(int i=0;i<s.length();++i){
		if(s[i]==t[pos])++pos;
		if(pos==5){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}