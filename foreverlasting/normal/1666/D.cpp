#include<bits/stdc++.h>
using namespace std;
#define res int
#define pb push_back
#define LL long long
#define gc getchar
inline int read(){
    res s=0,w=1,ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
const int N=100+10;
char s[N],t[N];
inline void solve(){
    scanf("%s",s+1),scanf("%s",t+1);
    res n=(int)(strlen(s+1)),m=(int)(strlen(t+1));
    res pre=n+1;
    for(res i=m;i>=1;i--){
        res fl=0;
        for(res j=pre-1;j>=1;j--){
            if(s[j]==t[i]){
                for(res k=j+1;k<pre;k++){
                    for(res l=1;l<j;l++)if(s[k]==s[l])s[l]=' ';
                }
                fl=1,pre=j;break;
            }
        }
//        printf("%s\n",s+1);
        if(!fl){puts("NO");return;}
    }
    puts("YES");
}
int main(){
    res T=read();
    while(T--){
        solve();
    }
    return 0;
}