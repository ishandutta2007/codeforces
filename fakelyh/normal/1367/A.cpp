#include<bits/stdc++.h>
using namespace std;
long long t;
string s;
inline long long read(){
    register long long num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
}
int main(){
	t=read();
	while(t--){
        cin>>s;
        cout<<s[0]<<s[1];
        for(register int i=2;i<s.length();i+=2)cout<<s[i+1];
        puts("");
    }
}