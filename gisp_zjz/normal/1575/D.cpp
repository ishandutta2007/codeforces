#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
string s,t;
int n;
int f(char c,int v){
    return (c=='0'+v)||(c=='_');
}
int work(string S,int x){
    int m=S.size();
    if (m-x==1) return f(S[x],0);
    int ret=0;
    ret+=f(S[m-2],0)&&f(S[m-1],0);
    ret+=f(S[m-2],2)&&f(S[m-1],5);
    ret+=f(S[m-2],5)&&f(S[m-1],0);
    ret+=f(S[m-2],7)&&f(S[m-1],5);
    for (int i=x;i<m-2;i++) if (S[i]=='_') ret*=10;
    return ret;
}
int solve(string S){
    if (S[0]=='0') return 0;
    if (S[0]=='_') return work(S,0)-work(S,1);
    return work(S,0);
}
int main(){
    cin >> s;
    n=s.size();
    if (n==1){
        if (s[0]>='1'&&s[0]<='9') puts("0"); else puts("1");
        return 0;
    }
    bool flag=0;
    for (int i=0;i<n;i++) flag|=s[i]=='X';
    if (!flag) printf("%d\n",solve(s));
    else {
        int ans=0;
        for (int i=0;i<10;i++){
            t=s;
            for (int j=0;j<n;j++) if (t[j]=='X') t[j]='0'+i;
            ans+=solve(t);
        }
        printf("%d\n",ans);
    }
}