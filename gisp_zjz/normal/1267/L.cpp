#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector <char> s[1005];
int n,l,k,r;
char c[1000005];

int main(){
    scanf("%d%d%d",&n,&l,&k);
    scanf("%s",c);
    sort(c,c+n*l);
    int pos=0; r=k-1;
    for (int i=1;i<=l;i++){
        char tmp=c[pos+r];
        for (int j=k-r;j<k;j++) {
            char res=c[pos++];
            if (res<tmp) r--;
            s[j].pb(res);
        }
        s[k].pb(c[pos++]);
    }
    for (int i=1;i<=n;i++)
        while (s[i].size()<l) s[i].pb(c[pos++]);
    for (int i=1;i<=n;i++){
        for (int j=0;j<l;j++) printf("%c",s[i][j]);puts("");
    }
    return 0;
}