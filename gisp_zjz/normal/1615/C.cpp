#include<bits/stdc++.h>
using namespace std;
char s[200005],t[200005];
int _,n;
int cnt(char *x){
    int sum=0;
    for (int i=0;i<n;i++) sum+=x[i]-'0';
    return sum;
}
int dif(char *x,char *y){
    int sum=0;
    for (int i=0;i<n;i++) sum+=x[i]!=y[i];
    return sum;
}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        scanf("%s",s);
        scanf("%s",t);
        int m=0;
        for (int i=0;i<n;i++) m+=s[i]!=t[i];
        int ans=n+1;
        if (cnt(s)==cnt(t)) ans=min(ans,dif(s,t));
        for (int i=0;i<n;i++) s[i]='0'+('1'-s[i]);
        if (cnt(s)+1==cnt(t)) ans=min(ans,dif(s,t));
        if (ans>n) ans=-1;
        printf("%d\n",ans);
    }
}