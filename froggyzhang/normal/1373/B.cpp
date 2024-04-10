#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
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
int T,n;
char s[110];
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=0;
		stack<int> st;
		for(int i=1;i<=n;++i){
			if(st.empty()||st.top()==s[i]-'0'){
				st.push(s[i]-'0');
			}
			else{
				st.pop();
				++ans;
			}
		}
		printf(ans&1?"DA\n":"NET\n");
	}
	return 0;
}