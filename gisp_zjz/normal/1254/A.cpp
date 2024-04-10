#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int n,m,k,ans[105][105],_,tot;
char s[105][105];
char f(int x){
    if (x>=1&&x<=10) return '0'+(x-1);
    if (x>=11&&x<=36) return 'a'+(x-11);
    if (x>=37&&x<=62) return 'A'+(x-37);
}
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d%d",&n,&m,&k);tot=0;
        for (int i=0;i<n;i++){
            scanf("%s",s[i]);
            for (int j=0;j<m;j++) tot+=s[i][j]=='R';
        }
        int cur=1,sum=0;
        for (int i=0;i<n;i++){
            if (i%2==0){
                for (int j=0;j<m;j++){
                    ans[i][j]=cur;
                    sum+=s[i][j]=='R';
                    if (cur<k&&sum>=tot*cur/k) ++cur;
                }
            } else {
                for (int j=m-1;j>=0;j--){
                    ans[i][j]=cur;
                    sum+=s[i][j]=='R';
                    if (cur<k&&sum>=tot*cur/k) ++cur;
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) printf("%c",f(ans[i][j]));
            printf("\n");
        }
    }
    return 0;
}