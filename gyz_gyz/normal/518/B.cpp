#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 200000
using namespace std;
int a[2][26],b[2][26],a1,a2,mi;char c[mx];
int main(){
    scanf("%s",c);
    for(int i=0;c[i];i++)
        if(c[i]<='Z')a[0][c[i]-'A']++;else a[1][c[i]-'a']++;
    scanf("%s",c);
    for(int i=0;c[i];i++)
        if(c[i]<='Z')b[0][c[i]-'A']++;else b[1][c[i]-'a']++;
    rep(i,0,25){
        if(a[0][i]>b[0][i])mi=b[0][i];else mi=a[0][i];
        a[0][i]-=mi;b[0][i]-=mi;a1+=mi;
        if(a[1][i]>b[1][i])mi=b[1][i];else mi=a[1][i];
        a[1][i]-=mi;b[1][i]-=mi;a1+=mi;
        if(a[0][i]<b[1][i])a2+=a[0][i];else a2+=b[1][i];
        if(a[1][i]<b[0][i])a2+=a[1][i];else a2+=b[0][i];    
    }
    printf("%d %d\n",a1,a2);
}