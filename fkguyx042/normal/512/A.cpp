 #include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
#define Maxn 105
char s[Maxn][Maxn],ans[30];
int in[Maxn];
bool link[26][26];
int i,j,n;
queue<int> p;
bool solve() { 
    int cnt = 0;
    for(i=0;i<26;i++) 
        if(in[i] == 0) p.push(i),ans[cnt++] = 'a' + i;  
    while(!p.empty()) {
        int now = p.front(); p.pop();
        for(int i = 0;i < 26;i++) {
            if(link[now][i]) {
                in[i]--;
                if(in[i] == 0) {
                    p.push(i);
                    ans[cnt++] = 'a' + i;
                }
            }
        }
    }
    ans[26] = '\0';
    if(cnt < 26)
        return false;
    else
        return true;
}
 
int main() {
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%s",&s[i]);
    bool flag=true;
    memset(link,false,sizeof(link));
    memset(in,0,sizeof(in));
    for(i=0;i<n-1&&flag;i++) {
        bool ok=false;
        int l1=strlen(s[i]),l2=strlen(s[i+1]);
        for(j=0;j<l1&&j<l2&&!ok;j++) {
            if(s[i][j]!=s[i+1][j]) { 
                ok=1;
                if(!link[s[i][j]-'a'][s[i+1][j]-'a']) in[s[i+1][j]-'a']++,link[s[i][j]-'a'][s[i+1][j]-'a'] = true;
            }
        }   
        if(!ok&&l1>l2) flag=0;
    }   
    if(!flag)  printf("Impossible\n");
    else {flag = solve();
        if(!flag) printf("Impossible\n");
        else printf("%s",ans);  }
    return 0;
}